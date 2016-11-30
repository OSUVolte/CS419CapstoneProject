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
//        me.game.viewport.follow(this.pos, me.game.viewport.AXIS.BOTH);
        
        // ensure the player is updated even when outside of viewport
        this.alwaysUpdate = true;
        
        this.playerOneSpawn = false;
        this.playerTwoSpawn = false;
    },

    /**
     * update the entity
     */
    update : function (dt) {
        if (me.input.isKeyPressed('d') && this.playerOneSpawn == false) {
            this.playerOneSpawn = true;
            var settings = {
                // the width of the path
                width: 784,
                height: 100,
                // the size of the entity
                framewidth: 32,                                     // minotaurs are 48 pixels in length
                frameheight: 32,
                // direction
                queueGroup: "queue_back",
                // which player spawned
                player: 1,
                shapes: [new me.Rect(0, 0, 25, 25)]
            }
            // spawn unit
            me.game.world.addChild(me.pool.pull("units", 100, 100, wizard, settings), 10);

        } else if (!me.input.isKeyPressed('d')) {
            this.playerOneSpawn = false;
        }

        if (me.input.isKeyPressed('a') && this.playerTwoSpawn == false) {
            this.playerTwoSpawn = true;
            var settings = {
                // the width of the path
                width: 784,
                height: 100,
                // the size of the entity
                framewidth: 48,
                frameheight: 48,
                // direction
                queueGroup: "queue_front",
                // which player spawned
                player: 2,
                shapes: [new me.Rect(0, 0, 25, 25)]             // make the shape smaller than the frame so that units collide when overlapping a bit
            }

            var settingssm = {
                // the width of the path
                width: 784,
                height: 100,
                // the size of the entity
                framewidth: 32,
                frameheight: 32,
                // direction
                queueGroup: "queue_front",
                // which player spawned
                player: 2,
                shapes: [new me.Rect(0, 0, 25, 25)]             // make the shape smaller than the frame so that units collide when overlapping a bit
            }
            
            me.game.world.addChild(me.pool.pull("units", 100, 160, minotaur, settings), 10);
            me.game.world.addChild(me.pool.pull("units", 100, 160, rogue, settings), 10);
        } else if (!me.input.isKeyPressed('a')) {
            this.playerTwoSpawn = false;
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
        settings.image = unit.image;
        if (unit.image == "minotaur spritesheet calciumtrice") {    // bigger frames
            settings.framewidth = 48;
            settings.frameheight = 48;
        }
        this._super(me.Entity, 'init', [x, y, settings, unit]);

        // set up unit stats
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
        this.type = "unit";
        this.waveRelease = false;
        this.wavetarget = "";

        // astar stats
        this.target_destination = null;
        this.myPath = [];
        this.dest = null;
        this.lastPos =  {x: -1, y: -1};
        this.pathAge = 0;

        // setup unit speeds
        var speed = Math.pow(2, -Math.abs(this.speed/5));
        this.body.setVelocity(this.speed, this.speed);                                                                                      // speed 8 = 0.35
        this.body.setMaxVelocity(this.speed, this.speed);                                                                                     // speed 8 = 3.5
        this.body.setFriction(speed, speed);

        this.hpBarCurrent = new me.Font("Verdana", 11, "green");
        this.hpBarCurrent.lineWidth = 1;
        this.hpBarCurrent.strokeStyle = new me.Color(0, 0, 0, 50);
        
        this.idle = true;
        this.queueGroup = settings.queueGroup;

        // player 1 is green hp bar, 2 is red hp bar
        if (this.player == 1) {
            this.hpBarCurrent.fillStyle = new me.Color(0, 255, 0, 50);
        } else {
            this.hpBarCurrent.fillStyle = new me.Color(255, 0, 0, 50);
        }
        this.hpBarMax = new me.Font("Verdana", 11, "black");
        this.hpBarMax.alpha = 0.5;
        // DO NOT follow position
//        me.game.viewport.follow(this.pos, me.game.viewport.AXIS.BOTH);
        
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
        this.renderable.addAnimation("attack", [30, 31, 32, 33, 34, 35, 36, 37, 38, 39], (1200 / this.speed));                 // 18.75 attackspeed multiplier
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
    },

    chessboard: function() {
        // return chessboard distance to target
     //   return Math.max( Math.abs(this.collisionBox.left - this.target.collisionBox.left), Math.abs(this.collisionBox.top - this.target.collisionBox.top));
        return Math.max( Math.abs(this.pos._x - this.target_destination.pos._x), Math.abs(this.pos._y - this.target_destination.pos._y));
    },

    // use draw function to draw hp bar
    draw : function(renderer) {
        var unitHp = "";
        var percent = this.hp / this.maxHp * 100;
        
        if (percent >= 80) {
            unitHp += "▄"
        }
        if (percent >= 60) {
            unitHp += "▄"
        }
        if (percent >= 40) {
            unitHp += "▄"
        }
        if (percent >= 20) {
            unitHp += "▄"
        }
        if (percent >= 0) {
            unitHp += "▄"
        }

        this._super(me.Entity, "draw", [renderer]);
        this.hpBarMax.draw(renderer, "▄▄▄▄▄", this.pos.x-4, this.pos.y-20);
        this.hpBarCurrent.draw(renderer, unitHp, this.pos.x-4, this.pos.y-20);
        this.hpBarCurrent.drawStroke(renderer, "▄▄▄▄▄", this.pos.x-4, this.pos.y-20);
    },

  /**
   * update the enemy pos
   */
    update : function (dt) {
        if(this.waveRelease === true) {
            this.waveRelease = false;

            endQueue();
            //Send to new target
            this.target_destination = this.wavetarget;
            this.dest = this.wavetarget;
        }

        // if (this.target_destination != null) {
        //     if (this.target_destination.alive == false) {
        //         this.target_destination = null;
        //     }
        // }
        // check if alive first
        if (this.hp <= 0 && this.alive) {
            this.body.collisionType = me.collision.types.NO_OBJECT;
            console.log(this.name + " : " + this.GUID + " >> DIED!");
            this.alive = false;

            //give money
            if(this.player == 1){
                game.dataAI.playergold += 20;
            }else{
                game.data.playergold += 20;
            }

            if (!this.renderable.isCurrentAnimation("dying") && !this.combat) {
                this.renderable.setCurrentAnimation("dying");
                this.renderable.setAnimationFrame();
            }
        }
    // if unit is alive and not in combat... continue walking
        if (this.alive && this.combat == false) {
            var now = Date.now();

            if (this.target_destination == null) {
                var closest = Number.MAX_VALUE;
                var temp_destination;

                for (var i = 0; i < me.game.world.children.length; i++) {                                           // get whatever target is the closest thing
                    if (me.game.world.children[i].player != this.player && me.game.world.children[i].player != undefined && me.game.world.children[i].alive) {
                        temp_destination = this.target_destination;
                        this.target_destination = me.game.world.children[i];
                        if (this.chessboard() <= closest) {
                            closest = this.chessboard();
                        } else {
                            this.target_destination = temp_destination;
                        }
                    }
                }
            }


            if (this.idle == true) {
                for (var i = 0; i < me.game.world.children.length; i++) {
                    if (me.game.world.children[i].name === this.queueGroup) {
                        this.target_destination = me.game.world.children[i];
                    }
                }
            }

            if (this.target_destination != null) {
                var cbdist = this.chessboard();
            }

            if (this.myPath.length < 1 || (cbdist >= 96 && this.pathAge+5000 < now)) {
                // not moving anywhere
                // friction takes over
                if (this.target_destination != null) {
                    this.myPath = me.astar.search(this.pos._x, this.pos._y, this.target_destination.pos._x, this.target_destination.pos._y);
                    this.dest = this.myPath.pop();
                    this.pathAge = now;
                }
            } else if (this.target_destination != null) {
                // if the unit is close enough
                if (this.chessboard() < 100000) {                                                                           // DISTANCE FROM THIS UNIT (500)
                    if (!this.renderable.isCurrentAnimation("walk")) {
                        this.renderable.setCurrentAnimation("walk");
                        this.renderable.setAnimationFrame();
                    }
                    // just go for it
                    this.dest = this.target_destination;
                    this.pathAge = now-5000;
    //            } else if (this.collisionBox.overlaps(this.dest.rect) && this.myPath.length > 0) {
    //                // TODO - do this with non constant, add some fuzz factor
                } else {    // if the unit is not close enough to target destination, just stand there
                    this.body.vel.x = 0;
                    this.body.vel.y = 0;

                    if (!this.renderable.isCurrentAnimation("stand") && !this.combat) {
                        this.renderable.setCurrentAnimation("stand");
                        this.renderable.setAnimationFrame();
                    }
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
                        this.left = "left";
                        if (this.name != "Minotaur") {
                            this.renderable.flipX(true);
                        }
                    } else if (xdiff > 2) {
                        this.body.vel.x += this.body.accel.x * me.timer.tick;
                        this.lastPos.x = this.body.pos.x;
                        this.facing = "right";
                        if (this.name != "Minotaur") {
                            this.renderable.flipX(false);
                        }
                    }

                    if (ydiff < -2) {
                        this.body.vel.y -= this.body.accel.y * me.timer.tick;
                        this.facing = "up";
                        this.lastPos.y = this.body.pos.y;
                    } else if (ydiff > 2) {
                        this.facing = "down";
                        this.body.vel.y += this.body.accel.y * me.timer.tick;
                        this.lastPos.y = this.body.pos.y;
                    }
                }
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
                    if(!this.target[0].alive || this.target[0] == undefined || this.target[0] == null) {
                        this.target.shift();
                    }
                } else {
                    this.combat = false;
                }
                
                // if there still exists a target and we are on frame 7, and we havent hit anything yet
                if (this.renderable.getCurrentAnimationFrame() == 7 && this.target.length != 0 && this.hit != true) {
                    this.hit = true;
                    this.target[0].renderable.flicker(500);
                    this.target[0].hp -= battle(this, this.target[0]);
                    this.target[0].health -= battle(this, this.target[0]);
//                    console.log(this.target[0].name + "(" + this.target[0].GUID + "): " + this.target[0].hp + "/" + this.target[0].maxHp);
                } else if (this.renderable.getCurrentAnimationFrame() != 7) {
                    // once unit leaves 7th 'hit' animation, reset hit switch
                    this.hit = false;
                }
            }
        }

        // update the body movement
        // handle collisions against other shapes
        if (!this.combat && this.alive) {
                this.body.update(dt);
                me.collision.check(this);
                this.body.setVelocity(1,1);
        }

        if (this.target_destination == null) {
            // this.body.vel.x = 0;
            // this.body.vel.y = 0;
            if (!this.renderable.isCurrentAnimation("stand") && !this.combat) {
                this.renderable.setCurrentAnimation("stand");
                this.renderable.setAnimationFrame();
            }
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
        if (response.b.body.collisionType != me.collision.types.WORLD_SHAPE
            && response.a.player !== response.b.player && response.b.player != undefined) {
        //this.body.setVelocity(0,0);

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
                    console.log("pushed new enemy")
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
            return false;
        }

        // bumped into a wall
        if (response.b.body.collisionType === me.collision.types.WORLD_SHAPE) {
            if (this.facing == "down") {
                this.body.vel.y -= Number.MAX_VALUE;
            } else if (this.facing == "up") {
                this.body.vel.y += Number.MAX_VALUE;
            } else if (this.facing == "right") {
                this.body.vel.x -= Number.MAX_VALUE
            } else if (this.facing == "left") {
                this.body.vel.x += Number.MAX_VALUE
            }

            //this.path++;
            return true;
        }

        return false;
    }
});

game.QueueArea = me.Entity.extend({
    init:function(x, y, settings) {
        this._super(me.Entity, 'init', [x, y , settings]);

        this.body.collisionType = me.collision.types.NO_OBJECT;
    },

    update : function (dt) {
        // return true if we moved or if the renderable was updated
        return (this._super(me.Entity, 'update', [dt]) || this.body.vel.x !== 0 || this.body.vel.y !== 0);
    },

    onCollision : function (response, other) {
        console.log("touching");
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
        
        this.body.setVelocity(15, 15);                      // so smooth walking oh yea
        this.body.setMaxVelocity(35, 35);                     // SO SMOOTH
        this.body.setFriction(0.05, 0.05);                      // THE SMOOTHEST
        
        // set the display to follow our position on both axis
    //    me.game.viewport.follow(this.pos, me.game.viewport.AXIS.BOTH);
        
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
    //    this.player = 1;
        this.target = [];
        this.targetedBy = [];
        this.gogetem = 1;

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
        this.body.collisionType = me.collision.types.NO_OBJECT;
        // set collision types
     //   this.body.setCollisionMask(me.collision.types.ENEMY_OBJECT | me.collision.types.WORLD_SHAPE);
        
        
        this.facing = "north";
    },

    // update player pos
    update : function (dt) {
        if (me.input.isKeyPressed('left')) {
                me.game.viewport.move(-100, 0);
        } else if (me.input.isKeyPressed('right')) {
                me.game.viewport.move(100, 0);

        } else if (me.input.isKeyPressed('up')) {
                me.game.viewport.move(0, -100);
        } else if (me.input.isKeyPressed('down')) {
            // going down
            me.game.viewport.move(0, 100);
        }

        // apply physics to the body (this moves the entity)
        this.body.update(dt);

        // handle collisions against other shapes

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
 //           console.log("I AM TOUCHING SOMETHING ELSE");
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
            if (this.chessboard() < 500) {                                                                              // DISTANCE FROM THIS UNIT (500)
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
// todo: maybe shields for the building (?)
function battle(attacker, defender) {
    var hpLost = 0;
    var hitChance = Math.floor((Math.random() * 100) + 1);
    if (hitChance <= attacker.hitPercent) {                                                 // if the attacker lands a hit
        var dodgeChance = Math.floor((Math.random() * 100) + 1);
        if (dodgeChance >= defender.dodge || defender.dodge == undefined) {                 // if the does not dodge
            if (attacker.attack - defender.def > 0 || attacker.name == "Wizard") {
                var critChance = Math.floor((Math.random() * 100) + 1);
                if (critChance <= attacker.crit) {
                    hpLost = (attacker.attack * 1.5) - defender.def;
                    if (attacker.name == "Wizard") {
                        hpLost = (attacker.attack * 1.5);
                    }
                    //console.log(defender.name + " (" + defender.GUID + "): -" + hpLost + "hp (CRIT)");
                } else {
                    hpLost = attacker.attack - defender.def;
                    if (attacker.name == "Wizard") {
                        hpLost = attacker.attack;
                    }
                    //console.log(defender.name + " (" + defender.GUID + "): -" + hpLost + "hp");
                }
            } else {
                hpLost = 0.5;                                                               // 0.5 hp lost even if defence of defender is too high
            }
        } else if (dodgeChance <= defender.dodge && defender.dodge != undefined) {
            console.log(defender.name + " (" + defender.GUID + "): DODGED!");
        }
    } else {
        console.log(attacker.name + " (" + defender.GUID + "): MISSED!");
    }

    return hpLost;
}

// stats passed for creating a unit class
function Unit(hp, def, atk, speed, hitPercent, dodge, type, crit, buildTime, name, image, cost) {
    this.hp = hp;
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
    this.crit = crit;
    this.qAssignment = -1;   // not assigned yet
    this.cost = cost; // add crit chance, 150% extra damage
}

/*
 * 200 point distribution between HP/ATK/DEF/SPEED/HIT/DODGE/CRIT
 *
 * warrior:     HP = 72         ATK = 20        DEF = 12        SPEED = 8                       // cost = 1x
 *              DODGE = 8       HIT = 75        CRIT = 5
 *
 * rogues:      HP = 50         ATK = 15        DEF = 5         SPEED = 15                      // cost = 1x
 *              DODGE = 15      HIT = 90        CRIT = 10
 *
 * wizard:      HP = 40         ATK = 40        DEF = 2         SPEED = 8                       // cost = 1x
 *              DODGE = 10      HIT = 98        CRIT = 0
 *
 * minotaur:    HP = 175        ATK = 50        DEF = 15        SPEED = 5                       // cost = 2x (300 point distribution allowed)
 *              DODGE = 0       HIT = 50        CRIT = 5
 *
 */
// Unit(hp, def, atk, speed, hitPercent, dodge, type, crit, buildTime, name, image)
var slime = new Unit(10, 1, 3, 20, 90, 3, "unit", 3, 10, "Slime", "slime spritesheet calciumtrice_0", 100);           // weak, fast build time
var rogue = new Unit(50, 5, 15, 25, 90, 15, "unit", 10, 10, "Rogue", "rogue spritesheet calciumtrice", 100);         // fast but weak
var warrior = new Unit(72, 12, 35, 8, 75, 8, "unit", 5, 10, "Warrior", "warrior spritesheet calciumtrice", 100);       // decent hp/def/attack, but prone to missing and slow
var wizard = new Unit(40, 2, 40, 18, 98, 10, "unit", 0, 10, "Wizard", "wizard spritesheet calciumtrice", 100);          // ignores defence/dodge chance, no chance for crit/slow
var minotaur = new Unit(175, 15, 50, 5, 50, 0, "unit", 5, 10, "Minotaur", "minotaur spritesheet calciumtrice", 100);      // strong, slow, lots of hp, most likely to miss, best for buildings

// todo:
// maybe implement archers/cleric









// end unit queueing
function endQueue() {
    console.log("endQueue fired");
    for (i = 0; i < me.game.world.children.length; i++) {
        if (me.game.world.children[i].idle == true ) {
            me.game.world.children[i].idle = false;
            me.game.world.children[i].target_destination = null;
        }
    }
}


game.WaveManager = me.Object.extend({
    init: function (x, y, settings){
        this.findAIBase = false;
        this.findPlayerBase = false;

        this.currentwave = game.data.currentwave;
        this.player1WaitLocation = "queue_mid";
        this.player1AttackLocation = "queue_front";

        this.player2WaitLocation = "p2_queue_mid";
        this.player2AttackLocation = "p2_queue_front";

        this.player1Base = "keep";
        this.player2Base = "p2_queue_front"; //TODO: change to player 2's keep location
    },

    update: function(){
        if(this.findAIBase == false){
            for (var i = 0; i < me.game.world.children.length; i++) {
                if (me.game.world.children[i].type === "barracks") {  //me.game.world.children[i].player == 2
                    this.player2Base = me.game.world.children[i]; //get entity object
                    this.findAIBase = true;
//                    console.log(me.game.world.children[i]);
                    }
                else if (me.game.world.children[i].name === "keep") {
                    this.player1Base = me.game.world.children[i];
                    this.findPlayerBase = true;
//                    console.log(me.game.world.children[i]);
                }
            }
        }
        if(this.currentwave < game.data.currentwave) {
            //Go to Next Wave
            this.currentwave = game.data.currentwave;
            console.log("Starting Wave: " + game.data.currentwave);

            //Send Units waiting at Queue Locations to Target Destination
            //TODO: Make ultimate target the other player's Base Building

            for (var i = 0; i < me.game.world.children.length; i++) {
                if (me.game.world.children[i].queueGroup === this.player1AttackLocation.name) {
                    console.log("send p1 units to p2 base");

                    me.game.world.children[i].target_destination = this.player2Base;
                    me.game.world.children[i].dest = this.player2Base;
                    me.game.world.children[i].wavetarget = this.player2Base;
                    me.game.world.children[i].waveRelease = true;
                }
                else if (me.game.world.children[i].queueGroup === "queue_front" && me.game.world.children[i].player == 2) {
                    console.log("send p2 units to p1 base");

                    me.game.world.children[i].target_destination = this.player1Base;
                    me.game.world.children[i].dest = this.player1Base;
                    me.game.world.children[i].wavetarget = this.player1Base;
                    me.game.world.children[i].waveRelease = true;
                }
            }

        }
    }

});


game.GameOverManager = me.Object.extend({
    init: function (x, y, settings){
        this.isPlayer1BaseAlive = true;
        this.isPlayer2BaseAlive = true;
    },

    update: function(){
        if(game.data.wavemanager.player1Base.alive == false) {
            // End the game.
            me.game.viewport.fadeOut("#000", 200);
            me.state.change(me.state.MENU_LOSE);
        }
    }
});

