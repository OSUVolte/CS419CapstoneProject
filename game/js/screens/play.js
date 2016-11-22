game.PlayScreen = me.ScreenObject.extend({
    /**
     *  action to perform on state change
     */
    onResetEvent: function() {
        // load level
        me.levelDirector.loadLevel("test_map2");

        // reset the score
        game.data.gametime = 0;

        //Build menu
        //todo add a map object then we wont need this...I think?
        game.data.buildbutton = me.pool.pull("buildbutton", 10, 10, {});

        //Add some menu functions
        //todo GET this into the HUD maybe?
        me.game.world.addChild(game.data.buildbutton, 30);
        game.data.menu_background = me.pool.pull("menu_background", 10, 100, {});
        game.data.barracksbutton = me.pool.pull("barracksbutton", 30, 110, {});

        //Add the HUD
        this.HUD = new game.HUD.Container();
        me.game.world.addChild(this.HUD);

    },

    /**
     *  action to perform when leaving this screen (state change)
     */
    onDestroyEvent: function() {
        // remove the HUD from the game world
        me.game.world.removeChild(this.HUD);
    }
});
