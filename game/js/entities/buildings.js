

game.Structures = me.Entity.extend({
    /**
     * constructor
     */
    init: function (x, y, settings) {

        //settings
        settings.image = "buildinga-footprint-spritesheet";
        settings.width = 32;
        settings.height = 32;

        //Settings for standard Building properties
        // to be passed on to the sub.
        settings.upm = 5; //unites per minute
        settings.capacity = 5;
        settings.cost = 100;


    }
});

game.Barracks = game.Structures.extend({
    /**
     * constructor
     */
    init:function (x, y, settings) {

        //settings
        settings.image= "barracks-footprint-spritesheet";
        settings.width= 32;
        settings.height= 32;

        //call the constructor
        this._super(me.DraggableEntity, 'init', [x, y , settings]);

        this.placed = false;

        this.chooseImage();

        // add a body shape
        this.body.addShape(new me.Rect(100,100, this.width, this.height));

    },
    /**
     * Change the image
     */
    chooseImage: function () {
        //todo make it update its color depending on whether or not placement is allowed
        this.renderable.addAnimation("neutral", [0], 5);
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






