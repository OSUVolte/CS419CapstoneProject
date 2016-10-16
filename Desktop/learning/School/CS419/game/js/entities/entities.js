/**
 * Player Entities
 */
 
 // the actual player, push keys in the update function will
 // control the screen
 // SO FAR:
 // if you push x on the keyboard, will spawn units, but will spawn many
 // TODO: fix unit spawning, then implement a way to create units
 // probably store the units gold, unit capacity, builds in this entity
game.PlayerEntity = me.Entity.extend({

    /**
     * constructor
     */
    init:function (x, y, settings) {

    
        // call the constructor
        this._super(me.Entity, 'init', [x, y , settings]);
        
                // set the default horizontal & vertical speed (accel vector)
        this.body.setVelocity(2,2);
        
        // set the display to follow our position on both axis
        me.game.viewport.follow(this.pos, me.game.viewport.AXIS.BOTH);
        
        // ensure the player is updated even when outside of viewport
        this.alwaysUpdate = true;
    },

    /**
     * update the entity
     */
    update : function (dt) {
            var created = false;
        if (me.input.isKeyPressed('x') && created == false) {

            setTimeout(function(){
            // spawns a warrior at location x: 32, y: 544, 1 unit, on object spawn_top
                me.game.world.addChild(me.pool.pull("spawn_top", 32, 544), 1);
                created = false;
            }, 2000);
            created = true;
        }

        // apply physics to the body (this moves the entity)
        this.body.update(dt);

        // handle collisions against other shapes
        me.collision.check(this);

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

// Entity for the bottom lane
// the lane is an entity from which we spawn a unit
// TODO: figure out a way to initialize settings variable dynamically,
// so we can use the lane entity to spawn different units
game.Bottom = me.Entity.extend({
    // constructor
    init : function (x, y, settings, combat, hp) {
        // settings is the entity property (https://melonjs.github.io/melonJS/docs/me.Entity.html)
        // can define things like sprite, framewidth of sprite, etc here
        var settings = {
            image: "slime spritesheet calciumtrice_0",
            // the width of the path
            width: 784,
            height: 100,
            
            // the size of the entity
            framewidth: 32,
            frameheight: 32,
            
            shapes: [new me.Rect(0, 0, 32, 32)]
        }
        
        var combat = false;
        var hp = 20;
        
        var width = settings.width;
        var height = settings.height;
        
        this._super(me.Entity, 'init', [x, y , settings, combat, hp]);
        
        // set the default horizontal & vertical speed (accel vector)
        this.body.setVelocity(2,2);
        
        // start/end position
        y = this.pos.y;
        x = this.pos.x;
        this.startX = x;
        this.endX = x + width - settings.framewidth;
        this.startY = y;
//        this.endY = y + height - settings.frameheight;
        // endY is hardcoded for now, figure out a way to determine it later
        this.endY = 256;
        this.combat = combat;
        this.hp = hp;
        
        console.log("endY = " + this.endY);
        console.log("after init combat = " + this.combat);

//        this.pos.x = x + width - settings.framewidth;
        
        this.walkRight = true;
        this.walkUp = false;
        
        this.body.setVelocity(1,1);
        
        // follow position
        me.game.viewport.follow(this.pos, me.game.viewport.AXIS.BOTH);
        
        this.alwaysUpdate = true;
    },
    
  /**
   * update the enemy pos
   */
    update : function (dt) {
        if (this.alive && this.combat == false) {
            if (this.walkRight && this.pos.x <= this.startX) {
//                console.log("walkright = false");
                this.walkRight = false;

            }
            else if (!this.walkRight && this.pos.x >= this.endX) {
                this.walkRight = true;
                this.walkUp = true;
//                console.log("walkright = true");
            }

            // make it walk
            this.renderable.flipX(this.walkRight);

            if (this.walkRight) {
                this.body.vel.x += -this.body.accel.x * me.timer.tick;
            } else {
                this.body.vel.x += this.body.accel.x * me.timer.tick;;
            }
            
            if (this.walkUp && this.pos.y > this.endY) {
                console.log("y = " + this.pos.y);
                this.body.vel.y += -this.body.accel.y * me.timer.tick;
                this.body.vel.x = 0;
            } else if (this.walkUp && this.pos.y < this.endY) {
                this.body.vel.y += this.body.accel.y * me.timer.tick;
                this.body.vel.x = 0;
            } else if (this.walkUp) {
                // reached destination
                this.body.vel.x = 0;
                this.body.vel.y = 0;
            } else {
                this.body.vel.y = 0;
            }
        }
        // if entity alive and engaged in combat, stop moving
        else if (this.alive && this.combat == true) {
            console.log("COMBAT = " + this.combat);
            this.body.vel.x = 0;
            this.body.vel.y = 0;
        }
        // if entity has died
        else {
            // TODO: call function for unit death, clean up unit and maybe play death animation
            this.body.vel.x = 0;
            this.body.vel.y = 0;
        }

        // update the body movement
        this.body.update(dt);

        // handle collisions against other shapes
        me.collision.check(this);

        // return true if we moved or if the renderable was updated
        return (this._super(me.Entity, 'update', [dt]) || this.body.vel.x !== 0 || this.body.vel.y !== 0);
    },

    /**
    * colision handler
    * (called when colliding with other objects)
    */
    onCollision : function (response, other) {
    if (response.b.body.collisionType !== me.collision.types.WORLD_SHAPE) {
        // if something touches this entity
      if (this.alive && (response.overlap > 0)) {
      // cause it to flicker
      // probably call battle function here
        this.combat = true;
        console.log("Engaged in combat! hp = " + this.hp);
        this.renderable.flicker(750);
        this.hp--;
        
        // call combat function, if this unit wins, they are no longer in combat and continue walking
        // else they are considered dead, for now, 
        if (this.hp > 0) {
            this.combat = false;
        } else {
            this.alive = false;
        }
      
      }
      return false;
    }
    // Make all other objects solid
    return true;
    }
});

// a simple warrior unit
// so far used to walk around and test the map, can move up down left right
// can remove before release, so we can have unit walk up to buildings/enemies
// and see if it will trigger the proper events
game.Warrior = me.Entity.extend({
    /**
     * constructor
     */
    init:function (x, y, settings) {
        var settings = {
            image: "warrior spritesheet calciumtrice",
            width: 32,
            height: 32,
            
            framewidth: 32,
            frameheight: 32,
            
            shapes: [new me.Rect(0, 0, 32, 32)]
        };

        // call the constructor
        this._super(me.Entity, 'init', [x, y , settings]);
        
        // set the default horizontal & vertical speed (accel vector)
        this.body.setVelocity(4,4);
        
        // set the display to follow our position on both axis
        me.game.viewport.follow(this.pos, me.game.viewport.AXIS.BOTH);
        
        // ensure the player is updated even when outside of viewport
        this.alwaysUpdate = true;
        
        // define standing animation, use all frames
        this.renderable.addAnimation("stand", [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
                                                    11, 12, 13, 14, 15, 16, 17, 18, 19]);
        
        // define walking animation
        this.renderable.addAnimation("walk", [20, 21, 22, 23, 24, 25, 26, 27, 28, 29]);
        
        // set standing as default
        this.renderable.setCurrentAnimation("stand");
    },

    // update player pos
    update : function (dt) {
        if (me.input.isKeyPressed('left')) {
            // flip the sprite on horizontal axis
            this.renderable.flipX(true);
           
            // update the entity velocity
            this.body.vel.x -= this.body.accel.x * me.timer.tick;

            // change to the walking animation
            if (!this.renderable.isCurrentAnimation("walk")) {
                this.renderable.setCurrentAnimation("walk");
                }
        } else if (me.input.isKeyPressed('right')) {
            // unflip the sprite
            this.renderable.flipX(false);

            // update the entity velocity
            this.body.vel.x += this.body.accel.x * me.timer.tick;

            // change to the walking animation
            if (!this.renderable.isCurrentAnimation("walk")) {
                this.renderable.setCurrentAnimation("walk");
            }
        } else if (me.input.isKeyPressed('up')) {
            // going up
            this.body.vel.y -= this.body.accel.y * me.timer.tick;
            // change to the walking animation
            if (!this.renderable.isCurrentAnimation("walk")) {
                this.renderable.setCurrentAnimation("walk");
            }
        } else if (me.input.isKeyPressed('down')) {
            // going down
            this.body.vel.y += this.body.accel.y * me.timer.tick;
            // change to the walking animation
            if (!this.renderable.isCurrentAnimation("walk")) {
                this.renderable.setCurrentAnimation("walk");
            }
        } else {
            // if doing nothing, dont move anywhere
            this.body.vel.x = 0;
            this.body.vel.y = 0;
            // change to the standing animation
            this.renderable.setCurrentAnimation("stand");
            var a = this.getBounds();
            var xpos = a.pos.x + (a.width / 2);
            var ypos = a.pos.y + (a.height / 2);
            //console.log("warrior: " + xpos + ", " + ypos);
        }

            // apply physics to the body (this moves the entity)
        this.body.update(dt);

        // handle collisions against other shapes
        me.collision.check(this);

        // return true if we moved or if the renderable was updated
        return (this._super(me.Entity, 'update', [dt]) || this.body.vel.x !== 0 || this.body.vel.y !== 0);
    },
   /**
     * colision handler
     * (called when colliding with other objects)
     */
    onCollision : function (response, other) {
        // Make all other objects solid
        return true;
    }
});





