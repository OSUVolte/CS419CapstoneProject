/**
 * a HUD container and child items
 */

game.HUD = game.HUD || {};


game.HUD.Container = me.Container.extend({

    init: function() {
        // call the constructor
        this._super(me.Container, 'init');

        // persistent across level change
        this.isPersistent = true;

        // make sure we use screen coordinates
        this.floating = true;

        // give a name
        this.name = "HUD";

        // add our child player gold object
        this.addChild(new game.HUD.PlayerGold(400, 10));
        // add chilc game time object
        this.addChild(new game.HUD.GameClock(800, 10));

    }
});

/**
 * a basic HUD item to display score
 */
game.HUD.PlayerGold = me.Renderable.extend({
    /**
     * constructor
     */
    init: function(x, y) {

        // call the parent constructor
        // (size does not matter here)
        this._super(me.Renderable, 'init', [x, y, 10, 10]);

        //create a font
        this.font = new me.BitmapFont("32x32_font", 32);
        this.font.set("right");

        // local copy of the global score
        this.playergold = -1;
        this.gametime = -1;
    },

    /**
     * update function
     */
    update : function () {
        // we don't do anything fancy here, so just
        // return true if the score has been updated
        if (this.playergold !== game.data.playergold) {
            this.playergold = game.data.playergold;
            return true;
        }
        return false;
    },

    /**
     * draw the score
     */
    draw : function (renderer) {
        // draw it baby !
        this.font.draw(renderer, "GOLD: "+game.data.playergold, this.pos.x, this.pos.y);
    }

});

game.HUD.GameClock = me.Renderable.extend({
    /**
     * constructor
     */
    init: function(x, y) {

        // call the parent constructor
        // (size does not matter here)
        this._super(me.Renderable, 'init', [x, y, 10, 10]);

        //create a font
        this.font = new me.BitmapFont("32x32_font", 32);
        this.font.set("right");

        this.starttime = me.timer.getTime();
        // local copy of the game's time clock
        this.gametime = -1;
    },

    /**
     * update function
     */
    update : function () {
        // we don't do anything fancy here, so just
        // return true if the game time has been updated
        if(me.timer.getTime() - this.gametime > 1000) {
            this.gametime += 1000;
            game.data.gametime = this.gametime;
            game.data.playergold += game.data.playergoldrate;
        }
        //console.log(this.gametime);
        //Check if the currentwave is also incremented
        if((game.data.currentwave+1) * game.data.waveduration < (game.data.gametime/1000)) {
            game.data.currentwave += 1;
            console.log("starting wave: " + game.data.currentwave);
        }
    },

    /**
     * draw the score
     */
    draw : function (renderer) {
        // draw it baby !
        this.font.draw(renderer, this.formattime(), this.pos.x, this.pos.y);
    },

    formattime: function() {
        var x = this.gametime / 1000;
        var seconds = x % 60;
        x /= 60;
        var minutes = x % 60;
        //console.log(seconds);
        if(seconds >=0 && seconds < 10)
            return Math.floor(minutes) + ":" + "0" + Math.floor(seconds);
        else
            return Math.floor(minutes) + ":" + Math.floor(seconds);
    }
});
