
/* Game namespace */
var game = {

    // an object where to store game information
    data : {
        // score
        score : 0,

        //Build menu
        buildbutton: "",
        barracksbutton: "",
        menu_background: "",

        playergold: 1000 //set initial player gold to 1000
    },


    // Run on page load.
    "onload" : function () {
        // Initialize the video.
        if (!me.video.init(1024, 768, {wrapper : "screen", scale : "auto", scaleMethod : "flex-width"})) {
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
        me.plugin.register(aStarPlugin, "astar");
        
        // Initialize the audio.
        me.audio.init("mp3,ogg");

        // set and load all resources.
        // (this will also automatically switch to the loading screen)
        me.loader.preload(game.resources, this.loaded.bind(this));
    },

    // Run on game resources loaded.
    "loaded" : function () {

        // load the texture atlas file
        // this will be used by object entities later
        game.texture = new me.video.renderer.Texture(
            me.loader.getJSON("UI_Assets"),
            me.loader.getImage("UI_Assets")
        );


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
        me.pool.register("units", game.Units, false);
        me.pool.register("queue", game.Queue);

        //Build Menu:
        me.pool.register("menu_background", game.BuildMenu, true);
        me.pool.register("buildbutton", game.BuildButton, true);
        me.pool.register("barracksbutton", game.BarracksButton, true);
        me.pool.register("player", game.PlayerEntity);

        //buildings:
        me.pool.register("build_area", game.BuildingArea);
        me.pool.register("structures", game.Structures);
        me.pool.register("Barracks", game.Structures);

        //Build Menu:
        me.pool.register("menu_background", game.BuildMenu, true);
        me.pool.register("buildbutton", game.BuildButton, true);
        me.pool.register("barracksbutton", game.BarracksButton, true);
        me.pool.register("build_menu", game.BuildingStatus, true);
        me.pool.register("player", game.PlayerEntity);
        me.pool.register("top", game.Top, false);
        me.pool.register("queue", game.Queue);

        // enable keyboard
        me.input.bindKey(me.input.KEY.LEFT,  "left");           // can add bind keys to play.js, under resetEvent function
        me.input.bindKey(me.input.KEY.RIGHT, "right");
        me.input.bindKey(me.input.KEY.UP,  "up");
        me.input.bindKey(me.input.KEY.DOWN, "down");
        
        //Buildings
        me.input.bindKey(me.input.KEY.B, "build", true);
        me.input.bindKey(me.input.KEY.NUM1, "barracks", true);
        me.input.bindKey(me.input.KEY.A, "accept");
        me.input.bindKey(me.input.KEY.X, "x", true);

        //unknown
        me.input.bindKey(me.input.KEY.Q, "q", true);

        //spawn Units
        me.input.bindKey(me.input.KEY.W, "makeType1", true);
        me.input.bindKey(me.input.KEY.R, "makeType2", true);
        me.input.bindKey(me.input.KEY.E, "makeType3", true);


        // render hitbox int the debug panel
        me.debug.renderHitBox = true;

        // Start the game.
        me.state.change(me.state.PLAY);
    }
};
