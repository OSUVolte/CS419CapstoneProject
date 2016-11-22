
/* Game namespace */
var game = {

    // an object where to store game information
    data : {
        // score
        score : 0,
        gametime: 0,
        currentwave: 0,
        waveduration: 15, //set to 15 seconds for testing

        //Build menu
        buildbutton: "",
        barracksbutton: "",
        menu_background: "",

        playergold: 1000, //set initial player gold to 1000
        playergoldrate: 5, //set initial player gold rate to 5 gold per sec

        attackMod: 0,
        defenseMod: 0,

        goldUpgradeLevel: 0,
        attackUpgradeLevel: 0,
        defenseUpgradeLevel: 0,

        upgradeLevelOneCost: 200,
        upgradeLevelTwoCost: 500,
        upgradeLevelThreeCost: 1000
    },


    // Run on page load.
    "onload" : function () {
        // Initialize the video.
        if (!me.video.init(1024, 768, {wrapper : "screen", scale : "auto", scaleMethod : "flex-width"})) {
            alert("Your browser does not support HTML5 canvas.");
            return;
        }
        me.sys.fps = 30;

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
        var upgradePressed = 0;

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
        me.pool.register("upgrade_menu", game.UpgradeMenu);

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

        //Upgrades
        me.input.bindKey(me.input.KEY.U, "upgrade", true);
        me.input.bindKey(me.input.KEY.G, "upgradeGold", true);
        me.input.bindKey(me.input.KEY.A, "upgradeAttack", true);
        me.input.bindKey(me.input.KEY.D, "upgradeDefense", true);


        // render hitbox int the debug panel
        me.debug.renderHitBox = true;

        // Start the game.
        me.state.change(me.state.PLAY);


        /**
        PLAYER UPGRADE ACTION HANDLER
        **/

        //Listen for upgrade press
        this.handler = me.event.subscribe(me.event.KEYDOWN, function (action, keyCode) {
            if (action === "upgrade") {          
                console.log("upgrade button pressed");
                upgradePressed = 1;
            }
        });

        //Listen for gold upgrade press
        this.handler = me.event.subscribe(me.event.KEYDOWN, function (action, keyCode) {
            if (action === "upgradeGold" && upgradePressed) {               
                console.log("upgrading gold");
                upgradePressed = 0;
                playerUpgrade("gold");
            }
        });

        //Listen for attack upgrade press
        this.handler = me.event.subscribe(me.event.KEYDOWN, function (action, keyCode) {
            if (action === "upgradeAttack" && upgradePressed) {               
                console.log("upgrading attack");
                upgradePressed = 0;
                playerUpgrade("attack");
            }
        });

        //Listen for defense upgrade press
        this.handler = me.event.subscribe(me.event.KEYDOWN, function (action, keyCode) {
            if (action === "upgradeDefense" && upgradePressed) {               
                console.log("upgrading defense");
                upgradePressed = 0;
                playerUpgrade("defense");
            }
        });

        function playerUpgrade(type) {
            switch(type) {
                case "gold":
                    if(game.data.goldUpgradeLevel == 0 && game.data.playergold > game.data.upgradeLevelOneCost) {
                        game.data.goldUpgradeLevel = 1; //upgrade to level 1
                        game.data.playergoldrate = 10;
                        game.data.playergold -= game.data.upgradeLevelOneCost; //charge player for upgrade
                        console.log("Player at Gold Earning Level 1");
                    } 
                    else if(game.data.goldUpgradeLevel == 1 && game.data.playergold > game.data.upgradeLevelTwoCost) {
                        game.data.goldUpgradeLevel = 2; //upgrade to level 2
                        game.data.playergoldrate = 20;
                        game.data.playergold -= game.data.upgradeLevelTwoCost; //charge player for upgrade
                        console.log("Player at Gold Earning Level 2");
                    } 
                    else if(game.data.goldUpgradeLevel == 2 && game.data.playergold > game.data.upgradeLevelThreeCost) {
                        game.data.goldUpgradeLevel = 3; //upgrade to level 3
                        game.data.playergoldrate = 30;
                        game.data.playergold -= game.data.upgradeLevelThreeCost; //charge player for upgrade
                        console.log("Player at Gold Earning Level 3");
                    }
                    else if(game.data.goldUpgradeLevel >= 3) {
                        console.log("No Gold Upgrades Left! Max Level!");
                    }
                    else {
                        console.log("Not enough gold for this upgrade");
                    }
                    break;
                case "attack":
                    if(game.data.attackUpgradeLevel == 0 && game.data.playergold > game.data.upgradeLevelOneCost) {
                        game.data.attackUpgradeLevel = 1; //upgrade to level 1
                        game.data.attackMod = 2;
                        game.data.playergold -= game.data.upgradeLevelOneCost; //charge player for upgrade
                        console.log("Player at Attack Mod Level 1");
                    } 
                    else if(game.data.attackUpgradeLevel == 1 && game.data.playergold > game.data.upgradeLevelTwoCost) {
                        game.data.attackUpgradeLevel = 2; //upgrade to level 2
                        game.data.attackMod = 4;
                        game.data.playergold -= game.data.upgradeLevelTwoCost; //charge player for upgrade
                        console.log("Player at Attack Mod Level 2");
                    } 
                    else if(game.data.attackUpgradeLevel == 2 && game.data.playergold > game.data.upgradeLevelThreeCost) {
                        game.data.attackUpgradeLevel = 3; //upgrade to level 3
                        game.data.attackMod = 6;
                        game.data.playergold -= game.data.upgradeLevelThreeCost; //charge player for upgrade
                        console.log("Player at Attack Mod Level 3");
                    }
                    else if(game.data.attackUpgradeLevel >= 3) {
                        console.log("No Attack Mod Upgrades Left! Max Level!");
                    }
                    else {
                        console.log("Not enough gold for this upgrade");
                    }
                    break;
                    break;
                case "defense":
                    if(game.data.defenseUpgradeLevel == 0 && game.data.playergold > game.data.upgradeLevelOneCost) {
                        game.data.defenseUpgradeLevel = 1; //upgrade to level 1
                        game.data.defenseMod = 2;
                        game.data.playergold -= game.data.upgradeLevelOneCost; //charge player for upgrade
                        console.log("Player at Defense Mod Earning Level 1");
                    } 
                    else if(game.data.defenseUpgradeLevel == 1 && game.data.playergold > game.data.upgradeLevelTwoCost) {
                        game.data.defenseUpgradeLevel = 2; //upgrade to level 2
                        game.data.defenseMod = 4;
                        game.data.playergold -= game.data.upgradeLevelTwoCost; //charge player for upgrade
                        console.log("Player at Defense Mod Earning Level 2");
                    } 
                    else if(game.data.defenseUpgradeLevel == 2 && game.data.playergold > game.data.upgradeLevelThreeCost) {
                        game.data.defenseUpgradeLevel = 3; //upgrade to level 3
                        game.data.defenseMod = 6;
                        game.data.playergold -= game.data.upgradeLevelThreeCost; //charge player for upgrade
                        console.log("Player at Defense Mod Earning Level 3");
                    }
                    else if(game.data.goldUpgradeLevel >= 3) {
                        console.log("No Defense Mod Upgrades Left! Max Level!");
                    }
                    else {
                        console.log("Not enough gold for this upgrade");
                    }
                    break;
                    break;
            }
        }
    }
};
