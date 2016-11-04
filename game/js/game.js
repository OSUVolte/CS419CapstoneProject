
/* Game namespace */
var game = {

    // an object where to store game information
    data : {
        // score
        score : 0
    },


    // Run on page load.
    "onload" : function () {
        // Initialize the video.
        if (!me.video.init(1024, 768, {wrapper : "screen", scale : "auto"})) {
            alert("Your browser does not support HTML5 canvas.");
            return;
        }

        // add "#debug" to the URL to enable the debug Panel
        if (me.game.HASH.debug === true) {
            window.onReady(function () {
                me.plugin.register.defer(this, me.debug.Panel, "debug", me.input.KEY.V);
            });
        }

        // astar plugin
//        me.plugin.register(aStarPlugin, "astar");
        
        // Initialize the audio.
        me.audio.init("mp3,ogg");

        // set and load all resources.
        // (this will also automatically switch to the loading screen)
        me.loader.preload(game.resources, this.loaded.bind(this));
    },

    // Run on game resources loaded.
    "loaded" : function () {
        me.state.set(me.state.MENU, new game.TitleScreen());
        me.state.set(me.state.PLAY, new game.PlayScreen());
        
        // disable gravity
        me.sys.gravity = 0;
        
        // prevent default browser actions
        me.input.preventDefault = true;

        // add our player entity in the entity pool
        me.pool.register("spawn_top", game.Warrior);
        me.pool.register("chaser", game.ChaserEntity);
        me.pool.register("player", game.PlayerEntity);
        me.pool.register("top", game.Top, false);

        // enable keyboard
        me.input.bindKey(me.input.KEY.LEFT,  "left");           // can add bind keys to play.js, under resetEvent function
        me.input.bindKey(me.input.KEY.RIGHT, "right");
        me.input.bindKey(me.input.KEY.UP,  "up");
        me.input.bindKey(me.input.KEY.DOWN, "down");
        
        me.input.bindKey(me.input.KEY.W, "w");
        me.input.bindKey(me.input.KEY.Q, "q");
        me.input.bindKey(me.input.KEY.R, "r");
        
        // Start the game.
        me.state.change(me.state.PLAY);
    }
};
