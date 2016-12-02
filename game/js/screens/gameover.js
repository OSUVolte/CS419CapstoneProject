game.GameOverScreen = me.ScreenObject.extend({
  /**
   * action to perform on state change
   */
  onResetEvent : function () {
  	if(game.data.player1win == 0) {
	    // Game over: Player 1 lose
	    var backgroundImage = new me.Sprite(
	      me.game.viewport.width / 2,
	      me.game.viewport.height / 2,
	      {
	        image: me.loader.getImage('game_over_lose'),
	      }
	    );
	}
	else{
	    // Game over: Player 1 win
	    var backgroundImage = new me.Sprite(
	      me.game.viewport.width / 2,
	      me.game.viewport.height / 2,
	      {
	        image: me.loader.getImage('game_over_win'),
	      }
	    );
	}
    // scale to fit with the viewport size
    backgroundImage.scale(me.game.viewport.width / backgroundImage.width, 1);

    // add to the world container
    me.game.world.addChild(backgroundImage, 1);


	  // change to play state on press Enter or click/tap
	  me.input.bindKey(me.input.KEY.ENTER, "enter", true);
	  me.input.bindPointer(me.input.pointer.LEFT, me.input.KEY.ENTER);
	  this.handler = me.event.subscribe(me.event.KEYDOWN, function (action, keyCode, edge) {
		  if (action === "enter") {
			  // play something on tap / enter
			  // this will unlock audio on mobile devices
			  me.audio.play("cling");
			  me.state.change(me.state.PLAY);
		  }
	  });
  },

  /**
   * action to perform when leaving this screen (state change)
   */
  onDestroyEvent : function () {
    me.input.unbindKey(me.input.KEY.ENTER);
    me.event.unsubscribe(this.handler);
  }
});