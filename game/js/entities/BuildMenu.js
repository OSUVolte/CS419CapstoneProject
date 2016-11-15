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

	},
	update: function () {
		return true;
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

		return false;
	},
	// mouse up function
	onRelease : function (/*event*/) {
		this.selected = false;

		//trigger the event
		me.input.triggerKeyEvent(me.input.KEY.B, false);
		me.input.triggerKeyEvent(me.input.KEY.NUM1, true);

		// close  building menu
		me.game.world.removeChild(game.data.menu_background);
		me.game.world.removeChild(game.data.barracksbutton);

		// don"t propagate the event furthermore
		return false;
	},

	update: function () {
		return true;
	},

	onDeactivateEvent: function() {
		me.input.triggerKeyEvent(me.input.KEY.NUM1, false);
		me.input.releasePointerEvent("pointerdown", this);
		me.input.releasePointerEvent("pointerup", this);
		me.input.releasePointerEvent("pointercancel", this);
	}

});

game.UI = game.UI || {};
// a Panel type container

game.UI.BuildingStatus = me.Container.extend({
	/**
	 *
	 * @param x
	 * @param y
	 * @param width
	 * @param height
	 * @param label - Title on the menu
	 * @param obj - is the building that called up the menu
	 */
	init: function(x, y, width, height, label, obj) {
		console.log('trying to load menu');
		// call the constructor
		this._super(me.Container, "init", [x+10, y+10, width, height]);

		// persistent across level change
		this.isPersistent = true;

		// make sure our object is always draw first
		this.z = 100;

		this.floating = true;

		// give a name
		this.name = label;
		this.building = obj;
		var bldg = this.building; // because I need to locally too!
									//writing txt on the menu is effing ugly!

		// background panel sprite
		this.panelSprite = game.texture.createSpriteFromName("background_1");
		this.panelSprite.anchorPoint.set(0, 0);
		//scale to match the container size
		this.panelSprite.scale(
			this.width / this.panelSprite.width,
			this.height / this.panelSprite.height
		);
		this.addChild(this.panelSprite);

		// Panel Label
		this.LabelText = new (me.Renderable.extend({
			init: function() {
				this._super(me.Renderable, 'init', [0, 0, 10, 10]);
				this.font = new me.Font("OpenSans-Regular", 20, "white");
				this.font.textAlign = "center";
				this.font.textBaseline = "top";
			},
			draw: function(renderer){
				this.font.draw (
					renderer,
					label ,
					this.pos.x,
					this.pos.y);
			}
		}));
		this.LabelText.pos.set(
			this.width / 2,
			16, // panel border
			this.z
		)
		this.addChild(this.LabelText, 10);


		// //this.displayInfo(60, 4, 10, "Capacity: "+ this.building.q.length +' / ' + this.building.capacity, this.building );
		// //this.displayInfo(80, 4, 10, "Health: "+ this.building.health, this.building );
		//display percent complete
		//this.displayInfo(40, 4, 10, "% Complete: "+ this.building.percentComplete );
		this.pcentCompText = new (me.Renderable.extend({
			init: function() {
				this._super(me.Renderable, 'init', [0, 0, 10, 10]);
				this.font = new me.Font("OpenSans-Regular", 10, "white");
				this.font.textAlign = "left";
				this.font.textBaseline = "top";
				this.building = bldg;
			},
			draw: function(renderer){
				this.font.draw (
					renderer,
					"% Complete: "+ this.building.percentComplete,
					this.pos.x,
					this.pos.y);
			}
		}));
		this.pcentCompText.pos.set(
			(this.width / 10)+ 6*((this.width / 10)),
			40, // panel border
			this.z
		)
		this.addChild(this.pcentCompText, 10);

		//display capactiy
		//this.displayInfo(60, 4, 10, "Capacity: "+ this.building.q.length +' / ' + this.building.capacity, this.building );
		this.capaText = new (me.Renderable.extend({
			init: function() {
				this._super(me.Renderable, 'init', [0, 0, 10, 10]);
				this.font = new me.Font("OpenSans-Regular", 10, "white");
				this.font.textAlign = "left";
				this.font.textBaseline = "top";
				this.building = bldg;
			},
			draw: function(renderer){
				this.font.draw (
					renderer,
					"Capacity: "+ this.building.q.length +' / ' + this.building.capacity,
					this.pos.x,
					this.pos.y);
			}
		}));
		this.capaText.pos.set(
			(this.width / 10)+ 6*((this.width / 10)),
			60, // panel border
			this.z
		)
		this.addChild(this.capaText, 10);

		//display health of building
		//this.displayInfo(80, 4, 10, "Health: "+ this.building.health, this.building );
		this.healthText = new (me.Renderable.extend({
			init: function() {
				this._super(me.Renderable, 'init', [0, 0, 10, 10]);
				this.font = new me.Font("OpenSans-Regular", 10, "white");
				this.font.textAlign = "left";
				this.font.textBaseline = "top";
				this.building = bldg;
			},
			draw: function(renderer){
				this.font.draw (
					renderer,
					"Health: "+ this.building.health,
					this.pos.x,
					this.pos.y);
			}
		}));
		this.healthText.pos.set(
			(this.width / 10)+ 6*((this.width / 10)),
			80, // panel border
			this.z
		)
		this.addChild(this.healthText, 10);

		// //watch the queue and add icons to menu
		// this.building.q.forEach(function(element, index){
		// 	var c  =1;
		// 	var size = this.building.q.length;
        //
		// 	me.game.world.addChild(new game.UI.UnitRemove(10*c,  30, 30, element, index, this));
		// 	c++;
		// });


		// input status flags
		this.selected = false;
		this.hover = false;
		// to memorize where we grab the shape
		this.grabOffset = new me.Vector2d(0,0);
	},
	//I would love to use this function but the text wont update, so thats why I have everything upstairs repeated.
	/*displayInfo: function(y, col, fontSize, text, bldg){

		// Panel Label
		this.CapacityText = new (me.Renderable.extend({
			init: function() {
				this._super(me.Renderable, 'init', [0, 0, 10, 10]);
				this.font = new me.Font("OpenSans-Regular", fontSize, "white");
				this.font.textAlign = "left";
				this.font.textBaseline = "top";
				this.bldg = bldg;
			},
			draw: function(renderer){
				this.font.draw (
					renderer,
					text,
					this.pos.x,
					this.pos.y);
			},

		}));
		this.CapacityText.pos.set(
			(this.width / 6) *col,
			y, // panel border
			this.z
		)
		this.addChild(this.CapacityText, 10);
	},*/

	onActivateEvent: function () {
		// register on the global pointermove event
		this.handler = me.event.subscribe(me.event.POINTERMOVE, this.pointerMove.bind(this));
		//register on mouse/touch event
		me.input.registerPointerEvent("pointerdown", this, this.onSelect.bind(this));
		me.input.registerPointerEvent("pointerup", this, this.onRelease.bind(this));
		me.input.registerPointerEvent("pointercancel", this, this.onRelease.bind(this));
		me.input.registerPointerEvent("pointerleave", this, this.onLeave.bind(this));

		// call the parent function
		this._super(me.Container, "onActivateEvent");
	},

	onDeactivateEvent: function () {
		// unregister on the global pointermove event
		me.event.unsubscribe(this.handler);
		// release pointer events
		me.input.releasePointerEvent("pointerdown", this);
		me.input.releasePointerEvent("pointerup", this);
		me.input.releasePointerEvent("pointercancel", this);
		me.input.releasePointerEvent("pointerleave", this);

		// call the parent function
		this._super(me.Container, "onDeactivateEvent");
	},

	/**
	 * pointermove function
	 */
	pointerMove: function (event) {
		this.hover = this.getBounds().containsPoint(event.gameX, event.gameY);

		if (this.selected) {
			// follow the pointer
			this.pos.set(event.gameX, event.gameY, this.pos.z);
			this.pos.sub(this.grabOffset);
			this.updateChildBounds();

		}

		//close the menu when we mouse away from it
		if(!this.hover){
			this.onLeave();
		}
	},

	// mouse down function
	onSelect : function (event) {
		if (this.hover === true) {
			this.grabOffset.set(event.gameX, event.gameY);
			this.grabOffset.sub(this.pos);
			this.selected = true;
			// don"t propagate the event furthermore
			return false;
		}
	},

	// mouse up function
	onRelease : function (/*event*/) {
		this.selected = false;
	},
	onLeave : function () {

		if(this.hover == false){
			this.selected = false;
			this.destroy();
			console.log("left")
		}
	},
	destroy: function(){
		me.game.world.removeChild(this);
	},

	// update function
	update : function(dt) {

		return this._super(me.Container, "update", [ dt ]) || this.hover ;
	}
});
