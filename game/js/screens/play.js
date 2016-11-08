game.PlayScreen = me.ScreenObject.extend({
    /**
     *  action to perform on state change
     */
    onResetEvent: function() {
        // load level
//        me.levelDirector.loadLevel("test_dungeon");
        me.levelDirector.loadLevel("test_map2");

        // reset the score
        game.data.score = 0;

        //Build menu
        //todo add a map object then we wont need this...I think?
        game.data.buildbutton = me.pool.pull("buildbutton", 10, 10, {});
        me.game.world.addChild(game.data.buildbutton, 30);
        game.data.menu_background = me.pool.pull("menu_background", 10, 100, {});
        // me.game.world.addChild(game.data.menu_background, 15);
        game.data.barracksbutton = me.pool.pull("barracksbutton", 30, 110, {});
        // me.game.world.addChild(game.data.barracksbutton, 30);

        // Add our HUD to the game world, add it last so that this is on top of the rest.
        // Can also be forced by specifying a "Infinity" z value to the addChild function.
        this.HUD = new game.HUD.Container();
        me.game.world.addChild(this.HUD);
//        me.game.world.addChild(me.pool.pull("spawn_top", 50, 50), 1);
        //me.game.world.addChild(new game.HUD.GUI_Button());
        // //for draggable pieces
        // var BarracksContainer = new me.Container(32, 32, 0, 600);
        // BarracksContainer.addChild(new game.Barracks(100, 100, {width: 32, height: 32, sprite:"buildinga-footprint-spritesheet"}), 6);
        // me.game.world.addChild(BarracksContainer);

        if(me.debug.renderHitBox){
            // display the current pointer coordinates on top of the pointer arrow
            me.game.world.addChild(new (me.Renderable.extend({
                init: function() {
                    this._super(me.Renderable, 'init', [0, 0, 10, 10]);
                    this.font = new me.Font("Arial", 10, "#FFFFFF");
                    this.font.textAlign = "center";
                    this.fontHeight = this.font.measureText(me.video.renderer, "DUMMY").height;
                },
                draw: function(renderer){
                    var x = Math.round(me.input.pointer.pos.x);
                    var y = Math.round(me.input.pointer.pos.y);
                    this.font.draw (
                        renderer,
                        "( " + x + "," + y + " )",
                        x,
                        y - this.fontHeight);
                }
            })), 100);
        }

    },

    /**
     *  action to perform when leaving this screen (state change)
     */
    onDestroyEvent: function() {
        // remove the HUD from the game world
        me.game.world.removeChild(this.HUD);
    }
});
