game.BuildButton = me.Entity.extend({
	init: function(x, y, settings) {
		this._super(me.Entity, "init", [x, y, {
			image: "buildbutton",
			width: 50,
			height: 49,
			spritewidth: "50",
			spriteheight: "49",
			getShape: function() {
				return (new me.Rect(0, 0, 50, 49)).toPolygon();
			}
		}]);
		this.floating = true; //follow screen
		this.body.setCollisionMask(me.collision.types.NO_OBJECT); //turn off collision detection

	},
	onActivateEvent: function () {
		me.input.registerPointerEvent("pointerdown", this, this.onMouseDown.bind(this));
		me.input.registerPointerEvent("pointerup", this, this.onRelease.bind(this));
		me.input.registerPointerEvent("pointercancel", this, this.onRelease.bind(this));
	},

	//callback for mouse click
	onMouseDown: function() {
	    if(game.data.isBuildMenuOpen == true){
//	    	console.log("close menu");
	    	// close  building menu
			me.game.world.removeChild(game.data.menu_background);
			me.game.world.removeChild(game.data.barracksbutton);
			me.game.world.removeChild(game.data.armourerbutton);
			me.game.world.removeChild(game.data.arsenalbutton);
			game.data.isBuildMenuOpen = false;
		}
		else{
			//Show Build Menu
//			console.log("open menu");
			game.data.menu_background = me.pool.pull("menu_background", 10, 100, {});
	        me.game.world.addChild(game.data.menu_background, 15);
	        game.data.barracksbutton = me.pool.pull("barracksbutton", 20, 110, {});
	        me.game.world.addChild(game.data.barracksbutton, 30);
	        game.data.armourerbutton = me.pool.pull("armourerbutton", 20, 190, {});
	        me.game.world.addChild(game.data.armourerbutton, 30);
	        game.data.arsenalbutton = me.pool.pull("arsenalbutton", 20, 270, {});
	        me.game.world.addChild(game.data.arsenalbutton, 30);
	        me.input.triggerKeyEvent(me.input.KEY.B, true);
//	        console.log("buildbutton pressed!");
	        game.data.isBuildMenuOpen = true;
	    }
		return false;
	},
	// mouse up function
	onRelease : function (/*event*/) {
		this.selected = false;
		
		me.input.triggerKeyEvent(me.input.KEY.B, false);

		// don"t propagate the event furthermore
		return false;
	},
	/**
	 * update function
	 */
	update: function () {
		return true;
	},

	onDeactivateEvent: function() {
		me.input.releasePointerEvent("pointerdown", this);
        me.input.releasePointerEvent("pointerup", this);
        me.input.releasePointerEvent("pointercancel", this);
	}


});
