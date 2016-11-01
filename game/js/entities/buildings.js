

game.Structures = me.Entity.extend({
    /**
     * constructor
     */
    init: function (x, y, settings) {

        // call the super constructor
        this._super(me.Entity, "init", [x, y, settings]);
        this.body.setCollisionMask(me.collision.types.NO_OBJECT);
    },
    onActivateEvent: function () {
        //register on mouse/touch event
        me.input.registerPointerEvent("pointerdown", this, this.onSelect.bind(this));
        me.input.registerPointerEvent("pointerup", this, this.onRelease.bind(this));
        me.input.registerPointerEvent("pointercancel", this, this.onRelease.bind(this));

        // register on the global pointermove event
        // If this causes issus see building_manager for alternative set up
        console.log("onActivate fired");
        this.handler = me.event.subscribe(me.event.POINTERMOVE, this.pointerMove.bind(this));
    },

    /**
     * pointermove function
     */
    pointerMove: function (event) {
        this.hover = false;
        //console.log(event.gameX, event.gameY);
        // move event is global (relative to the viewport)
        if (this.getBounds().containsPoint(event.gameX, event.gameY)) {
            // calculate the final coordinates
            var parentPos = this.ancestor.getBounds().pos;
            var x = event.gameX - this.pos.x - parentPos.x;
            var y = event.gameY - this.pos.y - parentPos.y;

            // the pointer event system will use the object bounding rect, check then with with all defined shapes
            for (var i = this.body.shapes.length, shape; i--, (shape = this.body.shapes[i]);) {
                if (shape.containsPoint(x, y)) {
                    this.hover = true;
                    break;
                }
            }
        }

        if (this.selected) {
            //todo show a menu or status or something

        }

        if (this.hover || this.selected) {
            return false;
        }
    },

    // mouse down function
    onSelect : function (event) {
        if (this.hover === true) {
            // this.grabOffset.set(event.gameX, event.gameY);
            // this.grabOffset.sub(this.pos);
            console.log('selected the new buiding');
            this.selected = true;

            me.game.world.addChild(me.pool.pull("top", this.pos.x, this.pos.y, rogue, {
                framewidth: 32,
                frameheight: 32,
                height: this.height,
                width: this.width,
                // direction
                lane: "top",

                // which player spawned
                player: 1,
                shapes: [new me.Rect(0, 0, 32, 32)]
            }), 10); //todo not sure about z index

            // don"t propagate the event furthermore
            return false;
        }
        return true;
    },

    // mouse up function
    onRelease : function (/*event*/) {
        this.selected = false;
        // close  building menu

        // don"t propagate the event furthermore
        return false;
    },
    /**
     * update function
     */
    update: function () {
        return this.selected || this.hover;
    }
});

//todo set up collisions on buildings
game.Barracks = game.Structures.extend({
    /**
     * constructor
     */
    init:function (x, y, settings) {

        //call the constructor
        this._super(game.Structures, 'init', [x, y , settings]);

        this.placed = true;
        this.bldgProperties();
        //this.chooseImage(); //todo set images correctly for barracks
        this.cost = 500; //cost for barracks is 500 gold

        this.body.addShape(new me.Rect(0,0, settings.width, settings.height));  // add a body shape
        this.renderable = new me.Sprite(0, 0, {image: me.loader.getImage("Barracks")}); //addimage
    },
    /**
     * Defines all the properties of the building
     *
     */
    bldgProperties: function(){

        this.buildTime = 60;
        this.est = Math.round(new Date().getTime()/1000);
        this.functional = false; //starts off as non-functional until build time expires
        //the types of units that this building can build
        this.enabled = {
            warrior:true,
            tank: false  // etc etc //todo add all unit types
        }; //
        this.upm = 5; //units per minute
        this.capacity = 5;
        this.cost = 100;
        this.health = 1000;
    },
    /**
     * Change the image
     */
    chooseImage: function () {
        //todo make it update its color depending on status (healthy, damaged, working, tobe destroyed etc)
        this.renderable.addAnimation("building", [0], 5);
        this.renderable.setCurrentAnimation("neutral");
    },
    /**
     * Set spawn point of the footprint
     * Might want to make it relative to some other entity
     */
    setSpawnPoint : function (dt) {
      //todo make this useable
        //I think it would be good to have this offset by a certain amount, but then it could potentially interfere with other buildings
        // so a check needs to be made
        //this.xcoor = dt.gameX;
        //this.ycoor = dt.gameY;
    },
    /**
     * update the entity
     */
    update : function (dt) {
        //Update functions of our game objects will always receive a delta time (in milliseconds).
        // It's important to pass it along to our parent's class update.
        //setting the time for the building
        this._super(me.Entity, "update", [dt]);

        //establish time elapsed since the placement
        this.now = Math.round(new Date().getTime()/1000);
        this.elapsed = this.now - this.est;

        //do something when its placed
        if(this.placed){

            //start construction
            if(this.elapsed > this.buildTime){
                this.allowBuild = true;
                this.chooseImage();//update the image when complete
            }
        }
        return this.selected || this.hover;
    },
   /**
     * collision handler
     * (called when colliding with other objects)
     */
    onCollision : function (response, other) {
        // Make all other objects solid
        return true;
    }
});







