/**
 * a HUD container and child items
 */

game.HUD = game.HUD || {};


game.HUD.Container = me.Container.extend({

    init: function() {
        // call the constructor
        this._super(me.Container, 'init');

        // persistent across level change
        this.isPersistent = false;

        // make sure we use screen coordinates
        this.floating = true;

        // give a name
        this.name = "HUD";

        // add our child player gold object
        this.addChild(new game.HUD.PlayerGold(500, 10));
        // add chilc game time object
        this.addChild(new game.HUD.GameClock(800, 10));

        // add child game message object
        this.addChild(new game.HUD.Message(me.video.renderer.getWidth(), me.video.renderer.getHeight()));
        // add child game message object
        //this.addChild(new game.HUD.AIMessage(800, me.video.renderer.getHeight() -50));

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
        this.gametime = 0;
    },

    /**
     * update function
     */
    update : function () {
        if(me.timer.getTime() - game.data.gametimeoffset - game.data.pauseoffset - this.gametime > 1075) {
            game.data.pauseoffset += me.timer.getTime() - game.data.gametimeoffset - game.data.pauseoffset - this.gametime;
            console.log(game.data.pauseoffset);
        }

        if(me.timer.getTime() - game.data.gametimeoffset - game.data.pauseoffset - this.gametime > 1000) {
            //console.log(this.gametime);
            this.gametime += 1000;
            game.data.gametime = this.gametime;
            game.data.playergold += game.data.playergoldrate;

            game.dataAI.playergold += game.dataAI.playergoldrate;                                                              // simply add gold to enemies dataAI
        }
        //console.log(this.gametime);
        //Check if the currentwave is also incremented
        if((game.data.currentwave+1) * game.data.waveduration < (game.data.gametime/1000)) {
            game.data.currentwave += 1;
            console.log("starting wave: " + game.data.currentwave);
            endQueue();
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


game.HUD.Message = me.Renderable.extend({
    /**
     * constructor
     */
    init: function(x, y) {

        // call the parent constructor
        // (size does not matter here)
        this._super(me.Renderable, 'init', [x, y, 10, 10]);
        this.msg = game.data.message.msg;

    },

    /**
     * update function
     */
    update : function () {

        this.updateMsg(me.timer.getTime());
        return true
    },

    /**
     * draw Messages
     */
    draw : function (renderer) {
        // draw it baby !
        renderer.setColor("#C0C0C0");
        renderer.fillRect(0, me.game.viewport.height-50, me.game.viewport.width/2, 50);
        renderer.setColor("#F0F0F0");
        renderer.fillRect(me.game.viewport.width/2, me.game.viewport.height-50, me.game.viewport.width/2, 50);
        //font
        if(game.data.message.player == 1){
            this.font = new me.Font("Arial", 20, game.data.message.color);
            this.font.textAlign = "center";
            this.font.textBaseline = "middle";
            this.font.draw(renderer, this.msg, this.pos.x/4, this.pos.y-25);
        }else{
            this.font = new me.Font("Arial", 20, game.data.message.color);
            this.font.textAlign = "center";
            this.font.textBaseline = "middle";
            this.font.draw(renderer, this.msg, this.pos.x/4 +(this.pos.x/4 *2) , this.pos.y-25);
        }
    },
    updateMsg : function (now){

        var duration = game.data.message.msgDur * 1000;
        //reset the message after 10 seconds when not empty
        if (this.msg != ""){
            if( now >= game.data.message.msgTime + duration){
                game.data.message.msg = ""
            }
        }
        this.msg = game.data.message.msg;
    }
});

// clickable hud container for start menu
game.HUD.ContainerTitle = me.Container.extend({

    init: function() {
        // call the constructor
        this._super(me.Container, 'init');

        // persistent across level change
        this.isPersistent = false;

        // make sure we use screen coordinates
        this.floating = true;

        // give a name
        this.name = "HUD_title";


        // add our child player gold object
        this.startButtEasy = this.addChild(new game.HUD.StartButtonEasy(440, 290));
        this.startButtHard = this.addChild(new game.HUD.StartButtonHard(440, 350));
    }
});

// hardmode button
game.HUD.StartButtonHard = me.Renderable.extend({
    /**
     * constructor
     */
    init: function(x, y) {

        // call the parent constructor
        // (size does not matter here)
        this._super(me.Renderable, 'init', [x, y, 256, 64]);

        //create a font
        this.font = new me.BitmapFont("32x32_font", 32);
    //    this.font.set("right");
        this.start = false;
    },
    
    onActivateEvent: function () {
		me.input.registerPointerEvent("pointerdown", this, this.onMouseDown.bind(this));
		me.input.registerPointerEvent("pointerup", this, this.onRelease.bind(this));
		me.input.registerPointerEvent("pointercancel", this, this.onRelease.bind(this));
	},
    
    onMouseDown: function() {
//		console.log("barracksbutton pressed!");
		me.input.triggerKeyEvent(me.input.KEY.NUM1, true);
		return false;
	},
    
	// mouse up function
	onRelease : function (/*event*/) {
		this.selected = false;

		//trigger the event
		//me.input.triggerKeyEvent(me.input.KEY.B, false);
		me.input.triggerKeyEvent(me.input.KEY.NUM1, false);

        me.audio.play("cling");
        this.start = true;
		return false;
	},

    /**
     * update function
     */
    update : function () {
        
        return true;
    },

    /**
     * draw the score
     */
    draw : function (renderer) {
        // draw it baby !
        this.font.draw(renderer, "HARD", this.pos.x, this.pos.y);
    },
    
    onDeactivateEvent: function() {
		me.input.triggerKeyEvent(me.input.KEY.NUM1, false);
		me.input.releasePointerEvent("pointerdown", this);
		me.input.releasePointerEvent("pointerup", this);
		me.input.releasePointerEvent("pointercancel", this);
	},

});

// ez pz mode button
game.HUD.StartButtonEasy = me.Renderable.extend({
    /**
     * constructor
     */
    init: function(x, y) {

        // call the parent constructor
        // (size does not matter here)
        this._super(me.Renderable, 'init', [x, y, 256, 64]);

        //create a font
        this.font = new me.BitmapFont("32x32_font", 32);
    //    this.font.set("right");
        this.start = false;
    },
    
    onActivateEvent: function () {
		me.input.registerPointerEvent("pointerdown", this, this.onMouseDown.bind(this));
		me.input.registerPointerEvent("pointerup", this, this.onRelease.bind(this));
		me.input.registerPointerEvent("pointercancel", this, this.onRelease.bind(this));
	},
    
    onMouseDown: function() {
//		console.log("barracksbutton pressed!");
		me.input.triggerKeyEvent(me.input.KEY.NUM1, true);
		return false;
	},
    
	// mouse up function
	onRelease : function (/*event*/) {
		this.selected = false;

		//trigger the event
		//me.input.triggerKeyEvent(me.input.KEY.B, false);
		me.input.triggerKeyEvent(me.input.KEY.NUM1, false);

        me.audio.play("cling");
        this.start = true;
		return false;
	},

    /**
     * update function
     */
    update : function () {
        
        return true;
    },

    /**
     * draw the score
     */
    draw : function (renderer) {
        // draw it baby !
        this.font.draw(renderer, "EASY", this.pos.x, this.pos.y);
    },
    
    onDeactivateEvent: function() {
		me.input.triggerKeyEvent(me.input.KEY.NUM1, false);
		me.input.releasePointerEvent("pointerdown", this);
		me.input.releasePointerEvent("pointerup", this);
		me.input.releasePointerEvent("pointercancel", this);
	},

});