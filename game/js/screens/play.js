game.PlayScreen = me.ScreenObject.extend({
    /**
     *  action to perform on state change
     */
    onResetEvent: function() {
        // load level
        me.levelDirector.loadLevel("test_map3-fakeIso");

        // reset the game data for keeping track of time a waves
        game.data.gametime = 0;
        game.data.gametimeoffset = me.timer.getTime(); //factor out time spent in title screen, game over screen, and previous games
        game.data.lastAIspawnTime = 0;
        game.data.currentwave = 0;
        game.data.playergold = 10000;
        game.data.player1win = 0;

        game.dataAI.gametime = 0;
        game.dataAI.currentwave = 0;
        game.data.playergold = 1000;
        game.data.structures = [];

        // reset upgrades
        // PLAYER
        game.data.atkBoost = 0; //attack boost
        game.data.defBoost = 0; // defence boost
        game.data.btBoost = 0; //buildtime Boost
        game.data.hpBoost = 0; //hp boost
        game.data.speedBoost = 0;
        game.data.dodgeBoost = 0;
        game.data.sfArmor = 1;
        game.data.sfSpeed = 1;
        game.data.sfHealth = 1;
        game.data.sfAtk = 1;
        game.data.sfBuildTime = 1;
        // AI
        game.dataAI.atkBoost = 0; //attack boost
        game.dataAI.defBoost = 0; // defence boost
        game.dataAI.btBoost = 0; //buildtime Boost
        game.dataAI.hpBoost = 0; //hp boost
        game.dataAI.speedBoost = 0;
        game.dataAI.dodgeBoost = 0;
        game.dataAI.sfArmor = 1;
        game.dataAI.sfSpeed = 1;
        game.dataAI.sfHealth = 1;
        game.dataAI.sfAtk = 1;
        game.dataAI.sfBuildTime = 1;

        //Build menu
        //todo add a map object then we wont need this...I think?
        game.data.buildbutton = me.pool.pull("buildbutton", 10, 10, {});

        //Add some menu functions
        //todo GET this into the HUD maybe?
        me.game.world.addChild(game.data.buildbutton, 30);
        game.data.menu_background = me.pool.pull("menu_background", 10, 100, {});
        game.data.barracksbutton = me.pool.pull("barracksbutton", 30, 110, {});

        // //Add the HUD
         this.HUD = new game.HUD.Container();
         me.game.world.addChild(this.HUD);

        //Add wave manager
        game.data.wavemanager = me.pool.pull("waveManager", 0, 0, {});
        me.game.world.addChild(game.data.wavemanager, 0);

        //Add game over manager
        game.data.gameovermanager = me.pool.pull("gameOverManager", 0, 0, {});
        me.game.world.addChild(game.data.gameovermanager, 0);

        // if(){
        //     // display the current pointer coordinates on top of the pointer arrow
        //     me.game.world.addChild(new (me.Renderable.extend({
        //         init: function() {
        //             this._super(me.Renderable, 'init', [0, 0, 10, 10]);
        //             this.font = new me.Font("Arial", 10, "#FFFFFF");
        //             this.font.textAlign = "center";
        //             this.fontHeight = this.font.measureText(me.video.renderer, "DUMMY").height;
        //         },
        //         draw: function(renderer){
        //             var x = Math.round(me.input.pointer.pos.x);
        //             var y = Math.round(me.input.pointer.pos.y);
        //             this.font.draw (
        //                 renderer,
        //                 "( " + x + "," + y + " )",
        //                 x,
        //                 y - this.fontHeight);
        //         }
        //     })), 100);
        //}

    },

    /**
     *  action to perform when leaving this screen (state change)
     */
    onDestroyEvent: function() {
        // remove the HUD from the game world
        me.game.world.removeChild(this.HUD);
    }
});
