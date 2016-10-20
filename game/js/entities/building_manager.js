game.BuildingManager = me.Container.extend({
    init : function (x,y, settings) {

        this._super(me.Container, "init", [x,y,settings]);

    }


    //Todo Add functions that are the logic for all buildings

    //what happens on building destroy

    //what happens when user kill building

    //what happens when....

});

/**
 * defines the path where building is allowed
 *
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
        if (me.input.isKeyPressed("build")) {
            var test;
            me.game.world.addChild(new game.FootPrint((this.pos.x+this.width)/2, (this.pos.y+this.height)/2, {width: 32, height: 32, bounds: this.bounds}), 10);
        }

        return this.selected || this.hover;
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