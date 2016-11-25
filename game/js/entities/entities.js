/**
 * Player Entities
 */
 // the actual player, push keys in the update function will
 // control the screen
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
        
        this.playerOneSpawn = false;
        this.playerTwoSpawn = false;

        this.qPressed = false;
    },

    /**
     * update the entity
     */
    update : function (dt) {
        if (me.input.isKeyPressed('w') && this.playerOneSpawn == false) {
            this.playerOneSpawn = true;
            var settings = {
                // the width of the path
                width: 784,
                height: 100,
                // the size of the entity
                framewidth: 32,
                frameheight: 32,
                // direction
                lane: "top",
                // which player spawned
                player: 1,
                shapes: [new me.Rect(0, 0, 25, 25)]
            }
            // spawn unit
            me.game.world.addChild(me.pool.pull("top", 16, 528, rogue, settings), 1);

        } else if (!me.input.isKeyPressed('x')) {
            this.playerOneSpawn = false;
        }

        if (me.input.isKeyPressed('q') && this.playerTwoSpawn == false) {
            this.playerTwoSpawn = true;
            var settings = {
                // the width of the path
                width: 784,
                height: 100,
                // the size of the entity
                framewidth: 32,
                frameheight: 32,
                // direction
                lane: "top",
                // which player spawned
                player: 2,
                shapes: [new me.Rect(0, 0, 25, 25)]             // make the shape smaller than the frame so that units collide when overlapping a bit
            }
            
            me.game.world.addChild(me.pool.pull("top", 752, 16, warrior, settings), 1);
        } else if (!me.input.isKeyPressed('q')) {
            this.playerTwoSpawn = false;
        }
        
        if (me.input.isKeyPressed('r') && this.qPressed == false) {
            this.qPressed = true;
            
        } else if (!me.input.isKeyPressed('q')) {
            this.qPressed = false;
            
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

//Units that are spawned into action

game.Units = me.Entity.extend({
    init : function (x, y, unit, settings) {
        var width = settings.width;
        var height = settings.height;
        settings.image = unit.image;
        
        this._super(me.Entity, 'init', [x, y, settings, unit]);
        
        // start/end position
        y = this.pos.y;
        x = this.pos.x;
        this.startX = x;
        this.endX = x + width - settings.framewidth;
        this.startY = y;

        // end is hardcoded for now
        this.endY = 16;
        this.combat = false;
        this.hp = (unit.hp + game.data.hpBoost) * game.data.sfHealth;
        this.maxHp = unit.maxHp;
        this.attack = (unit.atk + game.data.atkBoost) * game.data.sfAtk;
        this.def = (unit.def + game.data.defBoost) * game.data.sfArmor;
        this.speed = (unit.speed + game.data.speedBoost) * game.data.sfSpeed;
        this.hitPercent = unit.hitPercent;
        this.dodge = unit.dodge;
        this.type = unit.type;                              // type of unit, to be used to determine damage multipliers maybe?       
        this.name = unit.name;                              // unit name
        this.player = settings.player;                      // player 1 or 2
        this.target = [];                                   // target queue is empty
        this.targetedBy = [];                               // targeted by queue is empty
        this.hit = false;                                   // unit not performed an attack yet
        this.path = 0;
        this.gogetem = 1;
        
        // set the spawn point
        this.spawnPoint = "top";

        
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
        this.renderable.setAnimationFrame();
        
        // set the collision type, passed in settings option
        if (this.player == 1) {
            this.body.collisionType = me.collision.types.PLAYER_OBJECT;
        } else if (this.player == 2) {
            this.body.collisionType = me.collision.types.PLAYER_OBJECT;
        } else {
            this.body.collisionType = me.collision.types.NO_OBJECT;
        }
        
        
        // which way is the unit facing when spawned
        this.facing = "north";

        this.buildTime = (unit.buildTime - game.data.btBoost)* game.data.sfBuildTime;
        this.qAssignment = unit.qAssignment;

    },
    
  /**
   * update the enemy pos
   */
    update : function (dt) {
        // check if alive first
        if (this.hp <= 0 && this.alive) {
            this.body.collisionType = me.collision.types.NO_OBJECT;
            console.log(this.name + " : " + this.GUID + " >> DIED!");
            this.alive = false;
        }
    // if unit is alive and not in combat... continue walking
        if (this.alive && this.combat == false) {
        // set up the walking conditions for all units
            if (this.spawnPoint == "top") {
                if (this.path == 0) {
                    if (this.player == 1) {
                        this.body.vel.y += -this.body.accel.y * me.timer.tick;
                        this.body.vel.x = 0;
                    } else {
                        this.body.vel.y = 0;
                        this.body.vel.x -= this.body.accel.x * me.timer.tick;
                        this.renderable.flipX(true);
                    }
                }
                else if (this.path == 1) {
                    if (this.player == 1) {
                        this.body.vel.y = 0;
                        this.body.vel.x += this.body.accel.x * me.timer.tick;
                        this.renderable.flipX(false);
                    } else {
                        this.body.vel.y += this.body.accel.y * me.timer.tick;
                        this.body.x = 0;
                    }
                }
            }
            
            if (!this.renderable.isCurrentAnimation("walk")) {
                this.renderable.setCurrentAnimation("walk");
                this.renderable.setAnimationFrame();
            } 
        // if unit is dead
        } else if (!this.alive) {
            // when this unit dies, remove itself from the game
            if (this.renderable.getCurrentAnimationFrame() == 9 && !this.renderable.isCurrentAnimation("dead")) {
                this.renderable.setCurrentAnimation("dead");
                this.renderable.setAnimationFrame();
                me.game.world.removeChild(this);
            }
            this.body.vel.x = 0;
            this.body.vel.y = 0;
        }
        // if unit is alive and in combat
        else {
            // dont move
            this.body.vel.x = 0;
            this.body.vel.y = 0;
            // change to the standing animation if were not in combat and not currently standing (should never reach this ?)
            if (!this.renderable.isCurrentAnimation("stand") && !this.combat) {
                this.renderable.setCurrentAnimation("stand");
                this.renderable.setAnimationFrame();
            // if in combat, wait until animation 7 where we will hit the enemy
            } else if (this.combat) {
                // if target is not alive, pop off and get the next target, if there are no more
                // targets left, we are no longer in combat
                if (this.target.length > 0) {
                    if (!this.target[0].alive) {
                        this.target.shift();
                    }
                } else {
                    this.combat = false;
                }
                
                // if there still exists a target and we are on frame 7, and we havent hit anything yet
                if (this.renderable.getCurrentAnimationFrame() == 7 && this.target.length != 0 && this.hit != true) {
                    this.hit = true;
                    //console.log(this.target[0].renderable.flicker(500));
                    this.target[0].hp -= battle(this, this.target[0]);
                    //console.log(this.target[0].name + "(" + this.target[0].GUID + "): " + this.target[0].hp + "/" + this.target[0].maxHp);
                } else if (this.renderable.getCurrentAnimationFrame() != 7) {
                    // once unit leaves 7th 'hit' animation, reset hit switch
                    this.hit = false;
                }
            }
            else {
                this.combat = false;
            }
        }

        // update the body movement
        // handle collisions against other shapes
        if (!this.combat && this.alive) {
                this.body.update(dt);
                me.collision.check(this);
                this.body.setVelocity(1,1);
        }

        // return true if we moved or if the renderable was updated
        return (this._super(me.Entity, 'update', [dt]) || this.body.vel.x !== 0 || this.body.vel.y !== 0);
    },
    
        /**
    * colision handler
    * (called when colliding with other objects)
    */
    onCollision : function (response, other) {
    // IF we hit something that is NOT a GLOBAL_OBJECT, and something that IS NOT on the same team as us
        if (response.b.body.collisionType != me.collision.types.WORLD_SHAPE && response.a.player !== response.b.player) {
        this.body.setVelocity(0,0);
        this.body.vel.x = 0;
        this.body.vel.y = 0;
        // if this is alive
            if (this.alive && (response.overlap > 0)) {
                // loop through target array, if this enemy is new, push it to array
                var newEnemy = true;
                for (var i = 0; i < this.target.length; i++) {
                    if (this.target[i].GUID == other.GUID) {
                        newEnemy = false;
                    }
                }
                // if the enemy is new, push
                if (newEnemy === true) {
                    this.target.push(other);
                }
                // if this is the first fight, set the animation to attack
                if (this.combat == false) {
                    this.renderable.setCurrentAnimation("attack");
                    this.renderable.setAnimationFrame();
                    this.renderable.flicker(375);
                }
                this.combat = true;
                this.me = response.a;

            }
            return true;
        }

        
        // bumped into a wall
        if (response.b.body.collisionType === me.collision.types.WORLD_SHAPE) {
            this.path++;
            return true;
        }
        

        return false;
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
//        this.body.setVelocity(4,4);
        
        this.body.setVelocity(0.35, 0.35);                      // so smooth walking oh yea
        this.body.setMaxVelocity(3.5, 3.5);                     // SO SMOOTH
        this.body.setFriction(0.05, 0.05);                      // THE SMOOTHEST
        
        // set the display to follow our position on both axis
        me.game.viewport.follow(this.pos, me.game.viewport.AXIS.BOTH);
        
        // ensure the player is updated even when outside of viewport
        this.alwaysUpdate = true;
        this.alive = true;
        this.hp = 100;
        this.maxHp = 100;
        this.attack = 5;
        this.def = 5;
        this.hitPercent = 10;
        this.combat = false;
        this.hit = false;
        this.name = "TEST_WARRIOR";
        this.player = 1;
        this.target = [];
        this.targetedBy = [];
        
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
        this.renderable.setAnimationFrame();
        // set this collision type as ME
        this.body.collisionType = me.collision.types.PLAYER_OBJECT;
        // set collision types
        this.body.setCollisionMask(me.collision.types.ENEMY_OBJECT | me.collision.types.WORLD_SHAPE);
        
        
        this.facing = "north";
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
                this.renderable.setAnimationFrame();
                }
        } else if (me.input.isKeyPressed('right')) {
            // unflip the sprite
            this.renderable.flipX(false);

            // update the entity velocity
            this.body.vel.x += this.body.accel.x * me.timer.tick;

            // change to the walking animation
            if (!this.renderable.isCurrentAnimation("walk")) {
                this.renderable.setCurrentAnimation("walk");
                this.renderable.setAnimationFrame();
            }
        } else if (me.input.isKeyPressed('up')) {
            // going up
            this.body.vel.y -= this.body.accel.y * me.timer.tick;
            // change to the walking animation
            if (!this.renderable.isCurrentAnimation("walk")) {
                this.renderable.setCurrentAnimation("walk");
                this.renderable.setAnimationFrame();
            }
        } else if (me.input.isKeyPressed('down')) {
            // going down
            this.body.vel.y += this.body.accel.y * me.timer.tick;
            // change to the walking animation
            if (!this.renderable.isCurrentAnimation("walk") && !this.combat) {
                this.renderable.setCurrentAnimation("walk");
                this.renderable.setAnimationFrame();
            }
        } else if (!this.alive) {
            // when this unit dies, remove itself from the game AND remove its self from the list of attackers
            if (this.renderable.getCurrentAnimationFrame() == 9 && !this.renderable.isCurrentAnimation("dead")) {
                this.renderable.setCurrentAnimation("dead");
                this.renderable.setAnimationFrame();
                for (var i = 0; i < this.enemy.targetedBy.length; i++) {
                    if (this.enemy.targetedBy[i].GUID === this.GUID) {
                        this.enemy.targetedBy.splice(i, 1);
                        if (this.enemy.targetedBy.length != 0) {
                            this.enemy.target = this.enemy.targetedBy[0].GUID;
                        }
                    }
                }
                me.game.world.removeChild(this);
            }
            this.body.vel.x = 0;
            this.body.vel.y = 0;
        }
        else {
            // if doing nothing, dont move anywhere
            this.body.vel.x = 0;
            this.body.vel.y = 0;
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
        if (response.b.body.collisionType === me.collision.types.WORLD_SHAPE) {
            var ydif = this.pos.y - response.b.pos.y;
            var xdif = this.pos.x - response.b.pos.x;

            if (this.facing === "north" && ydif < 15) {
                this.pos.y--;                                                   // prevent passing through
            }
        }
        
    
    
    
    // if something that is an enemy touches this unit
        if (response.b.body.collisionType === me.collision.types.ENEMY_OBJECT) {
            // if something touches this entity while its alive...
            if (this.alive && this.combat == false) {
                this.me = response.a;
                this.enemy = other;
                this.target.push(other);
                this.combat = true;
                this.renderable.setCurrentAnimation("attack");
                this.renderable.setAnimationFrame();
                this.targetedBy.push(other);
            } else if (this.combat == true) {
                this.target.push(other);
                this.targetedBy.push(other);
                this.me = response.a;
                this.enemy = other;
            }
          return false;
        } else {
 //           console.log("I AM TOUCHING SOMETHING ELSE ewww");
            return true;
        }
        // Make all other objects solid
    return false;
    }
});

game.ChaserEntity = me.Entity.extend({
    /* -----
    constructor
    ------ */

    init: function(x, y, settings) {
        // call the constructor
        settings.image = "slime spritesheet calciumtrice_0",
        this._super(me.Entity, 'init', [x, y , settings]);

        // chase even when offscreen
        this.alwaysUpdate = true;
        // set the default horizontal & vertical speed (accel vector)
        this.body.setVelocity(0.25, 0.25);
        this.body.setMaxVelocity(3, 3);
        this.body.setFriction(0.05, 0.05);

        // adjust the bounding box
        // lower half SNES-RPG style
        this.hp = 10000;
        this.target = null;
        this.myPath = [];
        this.dest = null;
        this.lastPos =  {x: -1, y: -1};
        this.pathAge = 0;
        this.maxHp = 10000;
        this.def = 1;
        this.name = "slime";

    },

    chessboard: function() {

        // return chessboard distance to target
     //   return Math.max( Math.abs(this.collisionBox.left - this.target.collisionBox.left), Math.abs(this.collisionBox.top - this.target.collisionBox.top));
        return Math.max( Math.abs(this.pos._x - this.target.pos._x), Math.abs(this.pos._y - this.target.pos._y));
    },

    /* -----
    update the player pos
    ------ */
    update: function(dt) {
        var now = Date.now();
//        this.updateColRect(0, 16, 16, 16);
        if (this.target == null) {
            // we should globally store this value
            this.target = me.game.world.getChildByType(game.Warrior)[0];
        } else {
            for (var i = 0; i < me.game.world.children.length; i++) {
                if (me.game.world.children[i].gogetem == 1) {
                    this.target = me.game.world.children[i];
                }
            }
        }

        var cbdist = this.chessboard();

        if (this.myPath.length < 1 || (cbdist >= 96 && this.pathAge+5000 < now)) {
            // not moving anywhere
            // friction takes over
            if (this.target != null) {
                this.myPath = me.astar.search(this.pos._x, this.pos._y, this.target.pos._x, this.target.pos._y);
                this.dest = this.myPath.pop();
                this.pathAge = now;
                //console.log(this.dest);
            }
        } else {
            if (this.chessboard() < 500) {
                // just go for it
                this.dest = this.target;
                this.pathAge = now-5000;
//            } else if (this.collisionBox.overlaps(this.dest.rect) && this.myPath.length > 0) {
//                // TODO - do this with non constant, add some fuzz factor
            }
            if (this.dest != null) {

                //console.log("@",this.collisionBox.pos.x,this.collisionBox.pos.y);
                //console.log("Moving toward ",this.dest.pos.x,this.dest.pos.y);
                // move based on next position

                var xdiff = this.dest.pos.x - this.pos.x;
                var ydiff = this.dest.pos.y - this.pos.y;

                if (xdiff < -2) {
                    this.body.vel.x -= this.body.accel.x * me.timer.tick;
                    this.lastPos.x = this.body.pos.x;
                } else if (xdiff > 2) {
     //               this.flipX(true);
                    this.body.vel.x += this.body.accel.x * me.timer.tick;
                    this.lastPos.x = this.body.pos.x;
                }

                if (ydiff < -2) {
                    this.body.vel.y -= this.body.accel.y * me.timer.tick;
                    this.lastPos.y = this.body.pos.y;
                } else if (ydiff > 2) {
                    this.body.vel.y += this.body.accel.y * me.timer.tick;
                    this.lastPos.y = this.body.pos.y;
                }
            }
        }
        // check & update player movement
        this.body.update(dt);

        return (this._super(me.Entity, 'update', [dt]) || this.body.vel.x !== 0 || this.body.vel.y !== 0);


        // else inform the engine we did not perform
        // any update (e.g. position, animation)
        return false;
    },

    draw: function(context) {
        // draw the sprite if defined
            if (this.renderable) {
                // translate the renderable position (relative to the entity)
                // and keeps it in the entity defined bounds
                // anyway to optimize this ?
                var x = ~~(this.pos.x + (this.anchorPoint.x * (this.width - this.renderable.width)));
                var y = ~~(this.pos.y + (this.anchorPoint.y * (this.height - this.renderable.height)));
                context.translate(x, y);
                this.renderable.draw(context);
                context.translate(-x, -y);
            }
        // draw dest rect
        debugAStar = false;
        if (debugAStar && this.dest) {
            if (this.dest && this.dest.rect) {
                this.dest.rect.draw(context, "green");
            }   
            for (var i = 0, ii = this.myPath.length; i < ii; i+=1) {
                if (this.myPath[i] && this.myPath[i].rect) {
                    this.myPath[i].rect.draw(context, "red");
                }
            }
        }
    }

});



// takes the attacker object and defender object
// do calculations, returns the amount of damage done
// to the DEFENDER
function battle(attacker, defender) {
    var hpLost = 0;
    if (attacker.attack - defender.def > 0) {
        hpLost = attacker.attack - defender.def;
        //console.log(defender.name + " : -" + hpLost + "hp");
    }
    return hpLost;
}

// stats passed for creating a unit class
function Unit(hp, def, atk, speed, hitPercent, dodge, type, buildTime, name, image, cost) {
    this.hp = hp; // (hp + game.data.hpBoost) * game.data.sfHealth;
    this.maxHp = hp;
    this.def = def;
    this.atk = atk;
    this.speed = speed;
    this.hitPercent = hitPercent;
    this.dodge = dodge;
    this.type = type;
    this.name = name;
    this.image = image;
    this.buildTime = buildTime;
    this.qAssignment = -1;   // not assigned yet
    this.cost = cost

}


// Unit(hp, def, atk, speed, hitPercent, dodge, type, buildTime, name, image)
var slime = new Unit(10, 1, 3, 5, 90, 3, 1, 5, "Slime", "slime spritesheet calciumtrice_0", 100);
var rogue = new Unit(15, 2, 10, 10, 98, 30, 2, 10, "Rogue", "rogue spritesheet calciumtrice", 100);
var warrior = new Unit(10, 4, 5, 3, 70, 3, 3, 20, "Warrior", "warrior spritesheet calciumtrice", 100);





