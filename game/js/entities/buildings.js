

game.BuildingA = me.Entity.extend({

    /**
     * constructor
     */
    init:function (x, y) {

        // call the constructor

        // set the display to follow our position on both axis
        me.game.viewport.follow(this.pos, me.game.viewport.AXIS.BOTH);

        //keep it on the gameboard
        this.maxX = me.game.viewport.width - this.width;
        this.maxY = me.game.viewport.width - this.height;

        //this.body.collisionType = me.collision.types.ENEMY_OBJECT;
    },

    chooseImage: function () {
        //todo make it update its color depending on whhether or not placement is allowed
        this.renderable.addAnimation("neutral", [1], 1);
        this.renderable.setCurrentAnimation("neutral");
    },

    /**
     * update the entity
     */
    update : function (dt) {
        if (me.input.isKeyPressed('b')) {

            //now span it
            this._super(me.Entity, 'init', [x, y , {
                image: "buildinga-footprint-spritesheet",
                width: 32,
                height: 32
            }]);

            if (me.input.isKeyPressed("left")) {
                this.pos.x -= this.velx * time / 1000;
            }

            if (me.input.isKeyPressed("right")) {
                this.pos.x += this.velx * time / 1000;
            }

            if (me.input.isKeyPressed("down")) {
                this.pos.y -= this.velx * time / 1000;
            }

            if (me.input.isKeyPressed("up")) {
                this.pos.y += this.velx * time / 1000;
            }
            //If accept is placed add the buildingA to the grid.
            //todo add the conditions which allow it to be placed
            if (me.input.isKeyPressed("accept")) {
                //update image

                this.image = "bldgA";

                //glue it to the grid


            }

        }
        // else if (me.input.isKeyPressed('right')) {
        //     // unflip the sprite
        //     this.renderable.flipX(false);
        //
        //     // update the entity velocity
        //     this.body.vel.x += this.body.accel.x * me.timer.tick;
        //
        //     // change to the walking animation
        //     if (!this.renderable.isCurrentAnimation("walk")) {
        //         this.renderable.setCurrentAnimation("walk");
        //     }
        // }
        // else {
        //     this.body.vel.x = 0;
        //
        //     // change to the standing animation
        //     this.renderable.setCurrentAnimation("stand");
        // }
        //
        // if (me.input.isKeyPressed('jump')) {
        //     // make sure we are not already jumping or falling
        //     if (!this.body.jumping && !this.body.falling) {
        //         // set current vel to the maximum defined value
        //         // gravity will then do the rest
        //         this.body.vel.y = -this.body.maxVel.y * me.timer.tick;
        //
        //         // set the jumping flag
        //         this.body.jumping = true;
        //     }
        // }

        // apply physics to the body (this moves the entity)
        this.body.update(dt);

        // handle collisions against other shapes
        me.collision.check(this);


        this.pos.x = this.pos.x.clamp(0, this.maxX);
        this.pos.x = this.pos.y.clamp(0, this.maxY);

        // return true if we moved or if the renderable was updated
        return (this._super(me.Entity, 'update', [dt]) || this.body.vel.x !== 0 || this.body.vel.y !== 0);
    },

   /**
     * collision handler
     * (called when colliding with other objects)
     */
    onCollision : function (response, other) {
        // Make all other objects solid
        return true;
    }
});






