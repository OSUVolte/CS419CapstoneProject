
    //Todo Add functions that are the logic for all buildings

    //what happens on building destroy

    //what happens when user kill building

    //what happens when....

/**
 * defines the path where building is allowed
 * controls button pushes  (b for build)
 *
 */
game.Buildings = me.Renderable.extend({
    init: function (x, y, settings) {
        // set the coordinates to fit in the screen. Really it just needs any size greather than 0x0, and needs to be floating, so when the camera moves, it's always on screen
        this._super(me.Renderable, "init", [x, y, me.game.viewport.width, me.game.viewport.height]);
        this.floating = true;
        this.pos.x = x;
        this.pos.y = y;
        this.width = settings.width;
        this.height = settings.height;
        //setting this I need it to be inherited.
        //Surely there must be a way to get this, but I'm losing it in inheritance hell
        this.bounds = {
                x: x,
                y: y,
                width: this.width,
                height: this.height
        }
    },

    update: function () {

        //build
        if (me.input.isKeyPressed("build")) {
            console.log("build");
            this.isPlacing = true;
        }
        //build Barracks
        if (this.isPlacing == true && me.input.isKeyPressed("barracks")) {
            console.log("barracks");
            var test;
            me.game.world.addChild(new game.FootPrint((this.pos.x + this.width) / 2, (this.pos.y + this.height) / 2, {
                width: 32,
                height: 32,
                bounds: this.bounds,
                type: "barracks"
            }), 10);
            this.isPlacing = false;
        }

        return this.selected || this.hover;
    }

});

/**
 * BuildingObject is the starting point of any building
 * necessary for dragging and dropping of the footprint
 *
 */

game.BuildingObject = me.Entity.extend({
    /**
     * constructor
     */
    init: function (x, y, settings) {
        // ensure we do not create a default shape
        settings.shapes = [];
        // call the super constructor
        this._super(me.Entity, "init", [x, y, settings]);

        // status flags
        this.selected = false;
        this.hover = false;

        // to memorize where we grab the shape
        this.grabOffset = new me.Vector2d(0,0);

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
            // follow the pointer
            me.game.world.moveUp(this);
            this.pos.set(event.gameX, event.gameY, this.pos.z);
            this.pos.sub(this.grabOffset);
            this.checkPosition();
        }

        if (this.hover || this.selected) {
            return false;
        }
    },
    /*
     * Check the position  to be within the "build" area and updates the image
     */
    checkPosition : function () {
        //todo disallow building when out of bounds
        //todo flesh this out so it also checks for entities in the way
        console.log( this.bounds);

        if(this.pos.x > this.bounds.x
            && this.pos.x < this.bounds.width+this.bounds.x
            && this.pos.y > this.bounds.y
            && this.pos.y < this.bounds.width+this.bounds.y){
            //update the image
            console.log("is");
            this.chooseImage("good");

        }else{
            console.log("not")
            this.chooseImage("bad");
        }
    },
    // mouse down function
    onSelect : function (event) {
        if (this.hover === true) {
            this.grabOffset.set(event.gameX, event.gameY);
            this.grabOffset.sub(this.pos);
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

        this.checkPosition();
        //todo warn use when attempt to place outside of bounds

        //todo fix error from removal
        if(this.placeBuilding()){
            me.game.world.removeChild(this);
        };
        // don"t propagate the event furthermore
        return false;
    },

    /**
     * update function
     */
    update: function () {
        return this.selected || this.hover;
    },

    /**
     * draw the square
     */
    draw: function (renderer) {
        renderer.setGlobalAlpha(this.hover ? 1.0 : 0.5);
        this._super(me.Entity, "draw", [renderer]);
        renderer.setGlobalAlpha(0.80);
    }
});

game.FootPrint = game.BuildingObject.extend({
    /**
     * constructor
     */
    init: function (x, y, settings) {
        // call the super constructor
        //settings
        settings.image= settings.type + "-footprint-spritesheet";
        settings.width= 32;
        settings.height= 32;

        this._super(game.BuildingObject, "init", [x, y, settings]);

        // the bounds of the Building Container
        this.bounds = settings.bounds;


        // add a body shape
        this.body.addShape(new me.Rect(0, 0, this.width, this.height));

        //different sprite states determined by position of element
        this.renderable.addAnimation("neutral", [0]);
        this.renderable.addAnimation("bad", [1]);
        this.renderable.addAnimation("caution", [2]);
        this.renderable.addAnimation("good", [3]);

        //set the initial image
        this.chooseImage("neutral");
        this.checkPosition();

        //use to the track if it has been placed
        this.placed = false;
    },
    /**
     * Change the image
     */
    chooseImage: function (frameName) {
        this.renderable.setCurrentAnimation(frameName);
    },
    placeBuilding: function (){
        //if conditions are met
        console.log('placing a building...', this.type);
        //add building to the area.
        if(this.type == "barracks") {
            console.log("positioningbarracks:", this.pos.x , this.pos.y);
            me.game.world.addChild(new game.Barracks(this.pos.x , this.pos.y, {
                width: 32,
                height: 32,
                bounds: this.bounds,
                type: "barracks"
            }), 10);
            return true;
        }
    }
});

game.Queue = me.Renderable.extend({
    init: function (x, y, settings) {

        this._super(me.Renderable, "init", [0, 0, me.game.viewport.width, me.game.viewport.height]);
        this.floating = true;
        this.pos.x = x;
        this.pos.y = y;
        this.width = settings.width;
        this.height = settings.height;
    }
});

function buildBarracksButton() {
    console.log('building barracks!');
    me.input.triggerKeyEvent(me.input.KEY.B, true);
    me.input.triggerKeyEvent(me.input.KEY.NUM1, true);
    return;
}