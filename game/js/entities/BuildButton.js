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
		console.log("buildbutton pressed!");
		me.input.triggerKeyEvent(me.input.KEY.B, true);
		//Show Build Menu
		//game.data.menu_background = me.pool.pull("menu_background", 10, 100, {});
        me.game.world.addChild(game.data.menu_background, 15);
        //game.data.barracksbutton = me.pool.pull("barracksbutton", 30, 110, {});
        me.game.world.addChild(game.data.barracksbutton, 30);
		return false;
	},
	// mouse up function
	onRelease : function (/*event*/) {
		this.selected = false;
		// close  building menu

		// don"t propagate the event furthermore
		return false;
	},
	/**
	 * update function
	 */
	update: function () {
		return this.selected;
	}


});
