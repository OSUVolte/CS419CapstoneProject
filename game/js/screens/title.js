game.TitleScreen = me.ScreenObject.extend({
  /**
   * action to perform on state change
   */
  onResetEvent : function () {
    // title screen
    var backgroundImage = new me.Sprite(
      me.game.viewport.width / 2,
      me.game.viewport.height / 2,
      {
        image: me.loader.getImage('title_screen'),
      }
    );
    // scale to fit with the viewport size
    backgroundImage.scale(me.game.viewport.width / backgroundImage.width, 1);

    // add to the world container
    me.game.world.addChild(backgroundImage, 1);

    
  /**
   * action to perform when leaving this screen (state change)
   */
  onDestroyEvent : function () {
    me.input.unbindKey(me.input.KEY.ENTER);
    me.input.unbindPointer(me.input.pointer.LEFT);
    me.event.unsubscribe(this.handler);
  }
});