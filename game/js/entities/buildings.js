game.Barracks = me.DraggableEntity.extend({
    /**
     * constructor
     */
    init:function (x, y) {

        // call the constructor
        this._super(me.DraggableEntity, 'init', [x, y , {
            image: "buildinga-footprint-spritesheet",
            width: 32,
            height: 32
        }]);

        this.physicEditorContainer = new me.Container(50, 50, 400, 600);
        // set the default horizontal & vertical speed (accel vector)
        //this.body.setVelocity(4,4);

        //this.body.vel.y += this.body.accel.y * me.timer.tick;
        // set the display to follow our position on both axis
        //me.game.viewport.follow(this.pos, me.game.viewport.AXIS.BOTH);

        //keep it on the gameboard
        this.maxX = me.game.viewport.width - this.width;
        this.maxY = me.game.viewport.width - this.height;

        this.chooseImage();

        //this.body.collisionType = me.collision.types.ENEMY_OBJECT;
    },

    chooseImage: function () {
        //todo make it update its color depending on whether or not placement is allowed
        this.renderable.addAnimation("neutral", [1], 5);
        this.renderable.setCurrentAnimation("neutral");
    },

    /**
     * update the entity
     */
    update : function (dt) {


    //     if (me.input.isKeyPressed('build')) {
    //         //      //it should spawn
    //
    //         //for draggable pieces
    //     this.physicEditorContainer.addChild(new game.Barracks(200, 100, {
    //         width: 32,
    //         height: 32,
    //         sprite: "buildinga-footprint-spritesheet"
    //     }), 6);
    //     me.game.world.addChild(this.physicEditorContainer);
    // }

        //     if (me.input.isKeyPressed("left")) {
        //         this.pos.x -= this.velx * time / 1000;
        //     }
        //
        //     if (me.input.isKeyPressed("right")) {
        //         this.pos.x += this.velx * time / 1000;
        //     }
        //
        //     if (me.input.isKeyPressed("down")) {
        //         this.pos.y -= this.velx * time / 1000;
        //     }
        //
        //     if (me.input.isKeyPressed("up")) {
        //         this.pos.y += this.velx * time / 1000;
        //     }
        //     //If accept is placed add the buildingA to the grid.
        //     //todo add the conditions which allow it to be placed
        //     if (me.input.isKeyPressed("accept")) {
        //         //update image
        //
        //         this.image = "bldgA";
        //
        //         //glue it to the grid
        //
        //
        //     }else{
        //
        //
        //     }
        //
        // }
        //
        //
        // // apply physics to the body (this moves the entity)
        // this.body.update(dt);
        //
        // // handle collisions against other shapes
        // me.collision.check(this);
        //
        //
        //  this.pos.x = this.pos.x.clamp(0, this.maxX);
        //  this.pos.x = this.pos.y.clamp(0, this.maxY);
        //
        // // return true if we moved or if the renderable was updated
        // return (this._super(me.Entity, 'update', [dt]) || this.body.vel.x !== 0 || this.body.vel.y !== 0);
        return this.selected || this.hover;
    },
    //An attempt to get the object to be selected even with the Warrior in game
    onActivateEvent: function () {
        //register on mouse/touch event
        me.input.registerPointerEvent("pointerdown", this, this.onSelect.bind(this));
        me.input.registerPointerEvent("pointerup", this, this.onRelease.bind(this));
        me.input.registerPointerEvent("pointercancel", this, this.onRelease.bind(this));

        // register on the global pointermove event
        this.handler = me.event.subscribe(me.event.POINTERMOVE, this.pointerMove.bind(this));
    },
    /**
     * pointermove function
     */
    pointerMove: function (event) {
        this.hover = false;

        // move event is global (relative to the viewport)
        if (this.getBounds().containsPoint(event.gameX, event.gameY)) {
            // calculate the final coordinates
            var parentPos = this.ancestor.getBounds().pos;
            var x = event.gameX - this.pos.x - parentPos.x;
            var y = event.gameY - this.pos.y - parentPos.y;

            // the pointer event system will use the object bounding rect, check then with with all defined shapes
            for (var i = this.body.shapes.length, shape; i--, (shape = this.body.shapes[i]);) {
                if (shape.containsPoint(x, y)) {
                    this.hover = true;
                    break;
                }
            }
        }

        if (this.selected) {
            // follow the pointer
            me.game.world.moveUp(this);
            this.pos.set(event.gameX, event.gameY, this.pos.z);
            this.pos.sub(this.grabOffset);
        }

        if (this.hover || this.selected) {
            return false;
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
        return true;
    },

    // mouse up function
    onRelease : function (/*event*/) {
        this.selected = false;
        // don"t propagate the event furthermore
        return false;
    },

    /**
     * draw the square
     */
    draw: function (renderer) {
        renderer.setGlobalAlpha(this.hover ? 1.0 : 0.5);
        this._super(me.Entity, "draw", [renderer]);
        renderer.setGlobalAlpha(1.0);
    },

    //Attempted to use draggable entites first.

    // dragStart: function (e) {
    //     // call the super function
    //     this._super(me.DraggableEntity, "dragStart", [e]);
    //     //set properties or update image
    //
    // },
    // dragEnd: function (e) {
    //     // call the super function
    //     this._super(me.DraggableEntity, "dragEnd", [e]);
    //     //update image
    // },

   /**
     * collision handler
     * (called when colliding with other objects)
     */
    onCollision : function (response, other) {
        // Make all other objects solid
        return true;
    }
});


/*
* This will be used to define where the entity can be dropped.
* Somehowe there must be a way to a, confine this to an area
* and b, only allow drop if nothing else is already there
*
*
* CURRENTLY THIS IS ONLY COPY PASTA FROM EXAMPLES
* */

game.droptarget = me.DroptargetEntity.extend({
    /**
     * constructor
     */
    init: function (x, y, settings) {
        // call the parent constructor
        this._super(me.DroptargetEntity, "init", [x, y, settings]);
        // set the color to white
        this.color = "red";
        // set the font we want to use
        this.font = new me.Font("Verdana", 15, "black");
        this.font.bold();
        // set the text
        this.text = "Drop on me\n\nAnd I\"ll turn green\n\ncheckmethod: overlap";
    },
    /**
     * update function
     */
    update: function () {
        return true;
    },
    /**
     * draw the square
     */
    draw: function (renderer) {
        renderer.setColor(this.color);
        renderer.fillRect(this.pos.x, this.pos.y, 100, 100);
        this.font.draw(renderer, this.text, this.pos.x, this.pos.y);
    },
    /**
     * drop overwrite function
     */
    drop: function (e) {
        // save a reference to this to use in the timeout
        var self = this;
        // call the super function
        this._super(me.DroptargetEntity, "draw", [e]);
        // indicate a succesful drop
        this.color = "green";
        // set the color back to red after a second
        window.setTimeout(function () {
            self.color = "red";
        }, 1000);
    }
});






