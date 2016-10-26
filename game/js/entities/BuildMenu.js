game.BuildMenu = me.Entity.extend({
	init: function(x, y, settings) {
		this._super(me.Entity, "init", [x, y, {
			image: "menu_background",
			width: 100,
			height: 350,
			spritewidth: "100",
			spriteheight: "350",
			getShape: function() {
				return (new me.Rect(0, 0, 100, 350)).toPolygon();
			}
		}]);
		this.floating = true;
		this.body.setCollisionMask(me.collision.types.NO_OBJECT);
	},
	displayMenu: function(){
		console.log("Display Build Menu!");
	},
	hide: function(){

	}
});


//Barracks Button on the Build BuildMenu
game.BarracksButton = me.Entity.extend({
	init: function(x, y, settings) {
	this._super(me.Entity, "init", [x, y, {
		image: "barracksbutton",
		width: 60,
		height: 47,
		spritewidth: "60",
		spriteheight: "47",
		getShape: function() {
			return (new me.Rect(0, 0, 60, 47)).toPolygon();
		}
	}]);
	this.floating = true;
	this.body.setCollisionMask(me.collision.types.NO_OBJECT);

	},
	onActivateEvent: function () {
		me.input.registerPointerEvent("pointerdown", this, this.onMouseDown.bind(this));
		me.input.registerPointerEvent("pointerup", this, this.onRelease.bind(this));
		me.input.registerPointerEvent("pointercancel", this, this.onRelease.bind(this));
	},

	//callback for mouse click
	onMouseDown: function() {
		console.log("barracksbutton pressed!");

    	me.input.triggerKeyEvent(me.input.KEY.NUM1, true);

		return false;
	},
	// mouse up function
	onRelease : function (/*event*/) {
		this.selected = false;
		// close  building menu
		me.game.world.removeChild(game.data.menu_background);
		//game.data.barracksbutton = me.pool.pull("barracksbutton", 30, 110, {});
		me.game.world.removeChild(game.data.barracksbutton);
		// don"t propagate the event furthermore
		return false;
	},
	/**
	 * update function
	 */
	update: function () {
		return this.selected
	}
});