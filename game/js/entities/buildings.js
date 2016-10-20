

game.Structures = me.Entity.extend({
    /**
     * constructor
     */
    init: function (x, y, settings) {

        //settings

        //Settings for standard Building properties
        // to be passed on to the sub.
        settings.upm = 5; //unites per minute
        settings.capacity = 5;
        settings.cost = 100;

        // call the super constructor
        this._super(me.Entity, "init", [x, y, settings]);
    },
    onActivateEvent: function () {
        //register on mouse/touch event
        me.input.registerPointerEvent("pointerdown", this, this.onSelect.bind(this));
        me.input.registerPointerEvent("pointerup", this, this.onRelease.bind(this));
        me.input.registerPointerEvent("pointercancel", this, this.onRelease.bind(this));
        // register on the global pointermove event
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
            console.log('selected');
            this.selected = true;
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
// todo
game.Barracks = game.Structures.extend({
    /**
     * constructor
     */
    init:function (x, y, settings) {

        //settings
        //settings.width= x;
        //settings.height= y;
        settings.timeToBuild = 1000;

        //call the constructor
        this._super(game.Structures, 'init', [x, y , settings]);

        this.placed = true;

        //this.chooseImage();

        // add a body shape
        this.body.addShape(new me.Rect(0,0, 0, 0));
        //addimage
        this.renderable = new me.Sprite(0, 0, {image: me.loader.getImage("Barracks")});


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
        //this.xcoor = dt.gameX;
        //this.ycoor = dt.gameY;
    },
    /**
     * update the entity
     */
    update : function (dt) {
        //Update functions of our game objects will always receive a delta time (in milliseconds). It's important to pass it along to our parent's class update.
        //this._super(me.Sprite, "update", [dt]);

        //do something when its placed
        if(!this.placed){

            // set the renderable position to bottom center
            //this.anchorPoint.set(this.x.pos, this.y.pos);
           // this.onActivateEvent();
            //console.log("free roaming - not placed yet")
        }


        // // apply physics to the body (this moves the entity)
         //this.body.update(dt);
        //
        // // handle collisions against other shapes
        // me.collision.check(this);
        //
        //
         //this.pos.x = this.pos.x.clamp(0, this.maxX);
         //this.pos.x = this.pos.y.clamp(0, this.maxY);
        //
        // // return true if we moved or if the renderable was updated

        return this.selected || this.hover;
        //return true;
    },


    //Attempting to use draggable entities first.
    dragStart: function (e) {
        // call the super function
        this._super(me.DraggableEntity, "dragStart", [e]);
        //set properties or update image
        console.log('say waat?')

    },
    dragEnd: function (e) {
        // call the super function
        this._super(me.DraggableEntity, "dragEnd", [e]);
        //update image
    },

   /**
     * collision handler
     * (called when colliding with other objects)
     */
    onCollision : function (response, other) {
        // Make all other objects solid
        //return true;
    }
});


/*
* This will be used to define where the entity can be dropped.
* Somehowe there must be a way to a, confine this to an area
* and b, only allow drop if nothing else is already there
*
*
* CURRENTLY THIS IS ONLY COPY PASTA FROM EXAMPLES
* */

game.droptarget = me.DroptargetEntity.extend({
    /**
     * constructor
     */
    init: function (x, y, settings) {
        // call the parent constructor
        this._super(me.DroptargetEntity, "init", [x, y, settings]);
        // set the color to white
        this.color = "red";
        // set the font we want to use
        this.font = new me.Font("Verdana", 15, "black");
        this.font.bold();
        // set the text
        this.text = "Drop on me\n\nAnd I\"ll turn green\n\ncheckmethod: overlap";
    },
    /**
     * update function
     */
    update: function () {
        return true;
    },
    /**
     * draw the square
     */
    draw: function (renderer) {
        renderer.setColor(this.color);
        renderer.fillRect(this.pos.x, this.pos.y, 100, 100);
        this.font.draw(renderer, this.text, this.pos.x, this.pos.y);
    },
    /**
     * drop overwrite function
     */
    drop: function (e) {
        // save a reference to this to use in the timeout
        var self = this;
        // call the super function
        this._super(me.DroptargetEntity, "draw", [e]);
        // indicate a succesful drop
        this.color = "green";
        // set the color back to red after a second
        window.setTimeout(function () {
            self.color = "red";
        }, 1000);
    }
});






