
/* Game namespace */
var game = {

    // an object where to store game information
    data : {
        // score
        score : 0,
        gametime: 0,
        currentwave: 0,
        waveduration: 10, //set to 15 seconds for testing

        //Build menu
        buildbutton: "",
        barracksbutton: "",
        armourerbutton: "",
        arsenalbutton: "",
        menu_background: "",
        isBuildMenuOpen: false,

        wavemanager: "",
        playergold: 1000, //set initial player gold to 1000
        playergoldrate: 5, //set initial player gold rate to 5 gold per sec

        /**
         * Checks if user has enough moolah
         * @param amt amount to be deducted
         * @returns {boolean} true if deduction was successful
         */
        cashier: function(amt){
            if(this.playergold- amt < 0){
                game.data.message= {msgTime: me.timer.getTime(), msg:"Not enough money ", msgDur: 3, color:"red"};
                return false
            }else{
                this.playergold = this.playergold - amt;
            }
            return true;
        },

        //Used for displaying messages on the screen
        message: {
            msgTime: 0, //time message was entered
            msg: "",
            dur: 10, // duration of the message
            color: "black"
        },

        //tech
        atkBoost: 0, //attack boost
        defBoost: 0, // defence boost
        btBoost: 0, //buildtime Boost
        hpBoost: 0, //health boost
        speedBoost: 0,

        //tech Scaling Factors
        //todo increase scale factor per level perhaps (ie player gets leveled up set by a conditional, and then this increases the scaling factor by .01 or something)
        sfArmor: 1,
        sfSpeed: 1,
        sfHealth: 1,
        sfAtk: 1,
        sfBuildTime: 1

    },
    //If this then that happens in the game:
    conditionals : {

        //time at which q one will be released
        waveTime: function () {

        },
        /**
         * BUILDING RELATED
         */
        //When will  building of type2 (rogue) entities be allowed
        //when player has x units in play, and gold greater than unit cost
        type2Allowed: function () {

        },
        //When will  building of type3 (slime) entities be allowed
        //when player has x units in play, and gold greater than unit cost
        type3Allowed: function () {

        },


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
        me.plugin.register(aStarPlugin, "astar");
        
        // Initialize the audio.
        me.audio.init("mp3,ogg");

        // set and load all resources.
        // (this will also automatically switch to the loading screen)
        me.loader.preload(game.resources, this.loaded.bind(this));
    },

    // Run on game resources loaded.
    "loaded" : function () {

        // load the texture  file
        // this will be used by object entities later
        game.texture = new me.video.renderer.Texture(
            me.loader.getJSON("UI_Assets2"),
            me.loader.getImage("UI_Assets2")
        );

        me.state.set(me.state.MENU, new game.TitleScreen());
        me.state.set(me.state.PLAY, new game.PlayScreen());
        
        // disable gravity
        me.sys.gravity = 0;
        
        // prevent default browser actions
        me.input.preventDefault = true;

        // prevent game pauses when browser is out of focus
        me.sys.pauseOnBlur = false;
        me.sys.stopOnBlur = false;

        // add our player entity in the entity pool
        me.pool.register("spawn_top", game.Warrior);
        me.pool.register("chaser", game.ChaserEntity);
        me.pool.register("player", game.PlayerEntity);
        me.pool.register("units", game.Units, false);

        //buildings:
        me.pool.register("build_area", game.BuildingArea);
        me.pool.register("structures", game.Structures);


        //Build Menu:
        me.pool.register("menu_background", game.BuildMenu, true);
        me.pool.register("buildbutton", game.BuildButton, true);
        me.pool.register("barracksbutton", game.BarracksButton, true);
        me.pool.register("armourerbutton", game.ArmourerButton, true);
        me.pool.register("arsenalbutton", game.ArsenalButton, true);
        me.pool.register("build_menu", game.BuildingStatus, true);

        //player Postions
        me.pool.register("player", game.PlayerEntity);
        me.pool.register("top", game.Top, false);
        me.pool.register("queue", game.Queue);

        // queuing areas
        me.pool.register("queue_front", game.QueueArea);
        me.pool.register("queue_back", game.QueueArea);

        //wave manager
        me.pool.register("waveManager", game.WaveManager, true);

        // enable keyboard
        me.input.bindKey(me.input.KEY.LEFT,  "left");           // can add bind keys to play.js, under resetEvent function
        me.input.bindKey(me.input.KEY.RIGHT, "right");
        me.input.bindKey(me.input.KEY.UP,  "up");
        me.input.bindKey(me.input.KEY.DOWN, "down");
        
        //Buildings
        me.input.bindKey(me.input.KEY.B, "build", true);
        me.input.bindKey(me.input.KEY.NUM1, "barracks", true);
        me.input.bindKey(me.input.KEY.NUM2, "armourer", true);
        me.input.bindKey(me.input.KEY.NUM3, "arsenal", true);


        // debug quick unit spawning keys, remove later
        me.input.bindKey(me.input.KEY.Q, "q", true);
        me.input.bindKey(me.input.KEY.A, "a", true);
        me.input.bindKey(me.input.KEY.D, "d", true);

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
