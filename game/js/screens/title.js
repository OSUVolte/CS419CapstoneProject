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

    // add a new renderable component with the scrolling text
    me.game.world.addChild(new (me.Renderable.extend ({
      // constructor
      init : function () {
        this._super(me.Renderable, 'init', [0, 0, me.game.viewport.width, me.game.viewport.height]);

        // font for the scrolling text
        this.font = new me.BitmapFont("32x32_font", 32);

        // a tween to animate the arrow
        this.scrollertween = new me.Tween(this).to({scrollerpos: -2200 }, 10000).onComplete(this.scrollover.bind(this)).start();

        this.scroller = "A GAME PROJECT CREATED FOR OREGON STATE UNIVERSITY CS419 (FALL 2016)       CLICK MODE TO START              ";
        this.scrollerpos = 600;
        
        this.win = me.save.win;
        this.lose = me.save.lose;
        
        // //Add the HUD
         this.HUD = new game.HUD.ContainerTitle();
         me.game.world.addChild(this.HUD);

      },

      // some callback for the tween objects
      scrollover : function () {
        // reset to default value
        this.scrollerpos = 640;
        this.scrollertween.to({scrollerpos: -2200 }, 10000).onComplete(this.scrollover.bind(this)).start();
      },

      update : function (dt) {
        if (this.HUD != null && this.HUD != undefined) {
            if (this.HUD.startButtEasy.start) {
                me.state.change(me.state.PLAY);
                game.data.mode = "easy";
            }
            if (this.HUD.startButtHard.start) {
                me.state.change(me.state.PLAY);
                game.data.mode = "hard";
            }
        }
        return false;
      },

      draw : function (renderer) {
        this.font.draw(renderer, "VOLTE GAME PROJECT", 200, 50);
        this.font.draw(renderer, "START GAME", 345, 230);
        this.font.draw(renderer, "WON: " + this.win, 270, 450);
        this.font.draw(renderer, "LOST: " + this.lose, 520, 450);
        this.font.draw(renderer, this.scroller, this.scrollerpos, 550);
      },
      onDestroyEvent : function () {
        //just in case
        this.scrollertween.stop();
      }
    })), 2);

  },

  /**
   * action to perform when leaving this screen (state change)
   */
  onDestroyEvent : function () {
    game.data.gametime = 0;
  }
});