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
      // TODO: remove later when we get rid of testing  
        var combat = false;
        var hp = 200;
        
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

game.Mid = me.Entity.extend({
 init : function (x, y, settings, combat, hp) {
        // settings is the entity property (https://melonjs.github.io/melonJS/docs/me.Entity.html)
        // can define things like sprite, framewidth of sprite, etc here
        var settings = {
            image: "slime spritesheet calciumtrice_0",
            // the width of the path
            width: 784,
            height: 528,
            
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
        
        // start/end position
        y = this.pos.y;
        x = this.pos.x;
        this.startX = x;
        this.endX = width;
        this.startY = y;
//        this.endY = y + height - settings.frameheight;
        // endY is hardcoded for now, figure out a way to determine it later
        this.endY = height;
        this.combat = combat;
        this.hp = hp;

//        this.pos.x = x + width - settings.framewidth;
        
        this.diagonal = false;

        this.body.setVelocity(1,0.6);
        
        // follow position
        me.game.viewport.follow(this.pos, me.game.viewport.AXIS.BOTH);
        
        this.alwaysUpdate = true;
    },
    

  /**
   * update the enemy pos
   */
    update : function (dt) {
        if (this.alive && this.combat == false) {
            if (!this.diagonal && (this.pos.x <= this.endX) || (this.pos.y >= this.endY)) {
                this.body.vel.y += -this.body.accel.y * me.timer.tick;
                this.body.vel.x += this.body.accel.x * me.timer.tick;
            } else {
                this.diagonal = true;
                this.body.vel.x = 0;
                this.body.vel.y = 0;
            }
        }
        // if entity alive and engaged in combat, stop moving
        else if (this.alive && this.combat == true) {
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
      if (this.alive && (response.overlap > 0) && !this.combat) {
      // cause it to flicker
      // probably call battle function here
        this.combat = true;

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

game.Top = me.Entity.extend({
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
        
        // start/end position
        y = this.pos.y;
        x = this.pos.x;
        this.startX = x;
        this.endX = x + width - settings.framewidth;
        this.startY = y;

        // end is hardcoded for now
        this.endY = 16;
        this.combat = combat;
        this.hp = hp;
        this.attack = 500;
        this.def = 10;
        this.hit = 20;
        
        
        this.walkRight = false;
        this.walkUp = false;

        this.body.setVelocity(1,1);
        
        // follow position
        me.game.viewport.follow(this.pos, me.game.viewport.AXIS.BOTH);
        
        this.alwaysUpdate = true;
        
        // define standing animation, use all frames
        this.renderable.addAnimation("stand", [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                                    11, 12, 13, 14, 15, 16, 17, 18, 19]);
        // define death animation
        this.renderable.addAnimation("dying", [40, 41, 42, 43, 44, 45, 46, 47, 48, 49]);
        // define death animation
        this.renderable.addAnimation("dead", [49]);
        // define walking animation
        this.renderable.addAnimation("walk", [20, 21, 22, 23, 24, 25, 26, 27, 28, 29]);
        // define attacking animation
        this.renderable.addAnimation("attack", [30, 31, 32, 33, 34, 35, 36, 37, 38, 39], 150);
        // set standing as default
        this.renderable.setCurrentAnimation("stand");
    },
    
  /**
   * update the enemy pos
   */
    update : function (dt) {
        if (this.alive && this.combat == false) {
            if (!this.walkUp && this.pos.y > this.endY) {
                this.body.vel.y += -this.body.accel.y * me.timer.tick;
                this.body.vel.x = 0;
                walkUp = true;
                if (!this.renderable.isCurrentAnimation("walk")) {
                this.renderable.setCurrentAnimation("walk");
                }
            } else if (!this.walkUp && this.pos.y <= this.endY && this.pos.x < this.endX) {
                this.body.vel.y = 0;
                this.body.vel.x += this.body.accel.x * me.timer.tick;
                if (!this.renderable.isCurrentAnimation("walk")) {
                this.renderable.setCurrentAnimation("walk");
                }
            } else if (this.pos.x >= this.endX) {
                this.body.vel.x = 0;
                this.body.vel.y = 0;
                this.walkRight = true;
                if (!this.renderable.isCurrentAnimation("stand")) {
                this.renderable.setCurrentAnimation("stand");
                }
            }
        }
        // if entity alive and engaged in combat, stop moving
        else if (this.alive && this.combat == true) {
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
      if (this.alive && (response.overlap > 0) && this.combat == false) {
      // cause it to flicker
      // probably call battle function here
        this.combat = true;
        this.renderable.flicker(750);
       // this.hp--;
        this.renderable.setCurrentAnimation("attack");
        console.log("fight!");
        // call combat function, if this unit wins, they are no longer in combat and continue walking
        // else they are considered dead, for now, 
        if (this.hp > 0) {
       //     this.combat = false;
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
        this.alive = true;
        this.hp = 1000;
        this.attack = 20;
        this.def = 15;
        this.hit = 10;
        this.combat = false;
        this.hit = false;
        this.enemy;
        this.me;
        
        // define standing animation, use all frames
        this.renderable.addAnimation("stand", [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
                                                    11, 12, 13, 14, 15, 16, 17, 18, 19]);
        // define death animation
        this.renderable.addAnimation("dying", [40, 41, 42, 43, 44, 45, 46, 47, 48, 49], 150);
        // define death animation
        this.renderable.addAnimation("dead", [49]);
        // define walking animation
        this.renderable.addAnimation("walk", [20, 21, 22, 23, 24, 25, 26, 27, 28, 29]);
        // define attacking animation
        this.renderable.addAnimation("attack", [30, 31, 32, 33, 34, 35, 36, 37, 38, 39], 150);
        // set standing as default
        this.renderable.setCurrentAnimation("stand");

        //keep player in view
        this.maxX = me.game.viewport.width - this.width;
        this.maxY = me.game.viewport.width - this.height;
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
            if (!this.renderable.isCurrentAnimation("walk") && !this.combat) {
                this.renderable.setCurrentAnimation("walk");
            }
        } else if (!this.alive) {
            if (this.renderable.getCurrentAnimationFrame() == 9 && !this.renderable.isCurrentAnimation("dead")) {
                this.renderable.setCurrentAnimation("dead");
                me.game.world.removeChild(this);
            }
            this.body.vel.x = 0;
            this.body.vel.y = 0;
        }
        else {
            // if doing nothing, dont move anywhere
            this.body.vel.x = 0;
            this.body.vel.y = 0;
            // change to the standing animation if were not in combat
            if (!this.renderable.isCurrentAnimation("stand") && !this.combat) {
                this.renderable.setCurrentAnimation("stand");
            // if in combat, wait until animation 7 where we get "hit" by the enemy
            } else if (this.combat) {
//                if (this.renderable.getCurrentAnimationFrame() == 7 && this.hit == false) {

                if (this.enemy.renderable.current.idx == 7 && this.hit == false) {
                    this.hit = true;
                    this.hp = battle(this.me, this.enemy);

                    if (this.hp <= 0) {
                        this.alive = false;
                        this.combat = false;
                        this.hit = false;
                        this.renderable.setCurrentAnimation("dying");
                        this.renderable.flicker(750);
                    }
                } else if (this.renderable.getCurrentAnimationFrame() != 7) {
                    this.hit = false
                }
            }
            
        }

        // apply physics to the body (this moves the entity)
        this.body.update(dt);

        // handle collisions against other shapes
        me.collision.check(this);

        //kep player in viewport
        this.pos.x = this.pos.x.clamp(0, this.maxX);
        this.pos.y = this.pos.y.clamp(0, this.maxY);

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
          if (this.alive && (response.overlap > 0) && this.combat == false) {
            this.me = response;
            this.enemy = other;
            this.combat = true;
            this.renderable.flicker(750);
            this.hp--;

            // call combat function, if this unit wins, they are no longer in combat and continue walking
            // else they are considered dead, for now,
            console.log("fight..");
            this.renderable.setCurrentAnimation("attack");
          }
          else if (this.combat == true ) {
                this.me = response;
                this.enemy = other;
          }
          return true;
        } 
        // Make all other objects solid
    return false;
    }
});


// todo: make battle system more complicated
function battle(response, other) {
    console.log("BATTLE");
    var hpResponse = response.a.hp;
    
    hpResponse = hpResponse - other.attack + response.a.def
    console.log("PLAYER TAKES DAMAGE: " + hpResponse);
    
    return hpResponse;
}





