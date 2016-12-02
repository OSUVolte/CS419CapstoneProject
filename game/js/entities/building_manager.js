
    //Todo Add functions that are the logic for all buildings

    //what happens on building destroy

    //what happens when user kill building

    //what happens when....

/**
 * BuildingArea defines the path where building is allowed
 * controls the building area, button pushes  (b for build etc)
 *
 */
game.BuildingArea = me.Renderable.extend({
    init: function (x, y, settings) {
        // set the coordinates to fit in the screen. Really it just needs any size greather than 0x0, and needs to be floating, so when the camera moves, it's always on screen
        console.log(settings.width, settings.height, x ,y)

        this._super(me.Renderable, "init", [x, y, settings.width, settings.height]);
        this.pos.x = x;
        this.pos.y = y;
        this.width = settings.width;
        this.height = settings.height;
        //setting this I need it to be inherited.
        //Surely there must be a way to get this, but I'm losing it in inheritance hell
        this.bounds = {
                x: x,
                y: y,
                width: this.width,
                height: this.height
        };
        this.player= 1;
    },

    update: function () {

        //build
        if (me.input.isKeyPressed("build")) {
            console.log("build");
            this.isPlacing = true;
        }
        //What to do if building and type barracks
        if (this.isPlacing == true && me.input.isKeyPressed("barracks")) {
            game.data.message= {msgTime: me.timer.getTime(), msg:"Placing Barracks", msgDur: 5, color:"white"};

            //TODO: dynamically use cost of building instead of hardcoded "200"
            if(game.data.playergold >= 200) {
                console.log((this.pos.x + this.width) / 2, (this.pos.y + this.height) / 2);
                // Adding it to the world, at a place near the bounding box as set by the tiled map object
                me.game.world.addChild(new game.FootPrint((this.pos.x + this.width) / 2, (me.game.viewport.height - this.height/2), {
                    width: 192,
                    height: 192,
                    bounds: this.bounds, // we'll need them from the box to determine if we can buiild at that postion
                    type: "barracks",
                    player: this.player
                }), 10);
                game.data.playergold -= 200;
            }
            else {
                //display message
                game.data.message= {msgTime: me.timer.getTime(), msg:"Not enough Money", msgDur: 5, color:"red"};

            }
            console.log(game.data.playergold);
            this.isPlacing = false;

        //What to do if building and type Armourer
        }else if (this.isPlacing == true && me.input.isKeyPressed("armourer")) {

            //TODO: dynamically use cost of building instead of hardcoded "200"
            if(game.data.playergold >= 200) {
                // Adding it to the world, at a place near the bounding box as set by the tiled map object
                me.game.world.addChild(new game.FootPrint((this.pos.x + this.width) / 2, (me.game.viewport.height - this.height/2), {
                    width: 228,
                    height: 196,
                    bounds: this.bounds, // we'll need them from the box to determine if we can buiild at that postion
                    type: "armourer",
                    player: this.player
                }), 10);
                game.data.playergold -= 200;
            }
            else {
                //display message
                game.data.message= {msgTime: me.timer.getTime(), msg:"Not enough Money", msgDur: 5, color:"red"};

            }
            console.log(game.data.playergold);
            this.isPlacing = false;

        }else if (this.isPlacing == true && me.input.isKeyPressed("arsenal")) {

            //TODO: dynamically use cost of building instead of hardcoded "200"
            if(game.data.playergold >= 200) {
                // Adding it to the world, at a place near the bounding box as set by the tiled map object
                me.game.world.addChild(new game.FootPrint((this.pos.x + this.width) / 4, (me.game.viewport.height - this.height/2), {
                    width: 265,
                    height: 192,
                    bounds: this.bounds, // we'll need them from the box to determine if we can buiild at that postion
                    type: "arsenal",
                    player: this.player
                }), 10);
                game.data.playergold -= 200;
            }
            else {
                //display message
                game.data.message= {msgTime: me.timer.getTime(), msg:"Not enough Money", msgDur: 5, color:"red"};

            }
            console.log(game.data.playergold);
            this.isPlacing = false;
        }else if (this.isPlacing == true && me.input.isKeyPressed("keep")) {

            //TODO: dynamically use cost of building instead of hardcoded "200"
            if(game.data.playergold >= 200) {
                // Adding it to the world, at a place near the bounding box as set by the tiled map object
                me.game.world.addChild(new game.FootPrint((this.pos.x + this.width) / 4, (me.game.viewport.height - this.height/2), {
                    width: 341,
                    height: 288,
                    bounds: this.bounds, // we'll need them from the box to determine if we can buiild at that postion
                    type: "keep",
                    player: this.player
                }), 10);
                game.data.playergold -= 200;
            }
            else {
                //display message
                game.data.message= {msgTime: me.timer.getTime(), msg:"Not enough Money", msgDur: 5, color:"red"};

            }
            console.log(game.data.playergold);
            this.isPlacing = false;
        }


        return this.selected || this.hover;
    },
    addStructure: function(structure){
            this.structures.push(structure);
    }

});

game.BuildingAreaAI = me.Renderable.extend({
    init: function (x, y, settings) {
        // set the coordinates to fit in the screen. Really it just needs any size greather than 0x0, and needs to be floating, so when the camera moves, it's always on screen
        console.log(settings.width, settings.height, x ,y)

        this._super(me.Renderable, "init", [x, y, settings.width, settings.height]);
        this.pos.x = x;
        this.pos.y = y;
        this.width = settings.width;
        this.height = settings.height;
        //setting this I need it to be inherited.
        //Surely there must be a way to get this, but I'm losing it in inheritance hell
        this.bounds = {
            x: x,
            y: y,
            width: this.width,
            height: this.height
        }

        this.structureProperties = {
            player: 2,
            time: '',
            id: ''
        }

        this.structures = []; // Array to hold all structures in play.

        /* new variables added */
        // set name
        this.name = "P2_build_area";
        this.buildingToBuild = "none";
        this.alwaysUpdate = true;
        
        // new stuff as well
        this.buildings = 0;
        this.newXpos = 0;
        this.newYpos = 0;
    },

    // enemyAI entity will call this when it builds, passing the type of building as an argument
    build : function(type) {
        this.buildingToBuild = type;
    },

    update: function () {

        //build                                                                                                                              // isPlacing will be triggered in the enemyAI entity
        //if (me.input.isKeyPressed("build")) {
        //    console.log("build");
        //    this.isPlacing = true;
        //}

        //What to do if building and type barracks
        if (this.isPlacing == true && this.buildingToBuild === "barracks") {
            game.data.message= {msgTime: me.timer.getTime(), msg:"ENEMY Placing Barracks", msgDur: 5, color:"white"};

            //TODO: dynamically use cost of building instead of hardcoded "200"
            if(game.dataAI.playergold >= 200) {
                // Adding it to the world, at a place near the bounding box as set by the tiled map object
                me.game.world.addChild(new game.FootPrint((this.pos.x + this.newXpos), (this.pos.y + 1 + this.newYpos), {                                                 // not sure if y position is off by 1 pixel when initialized (?)
                    width: 192,
                    height: 192,
                    bounds: this.bounds, // we'll need them from the box to determine if we can build at that postion
                    type: "barracks",

                    builder: "AI",                                                                                                           // builder AI is building
                    player: this.structureProperties.player                                                                                                                // pass to barracks that its building owned by player
                }), 10);
                game.dataAI.playergold -= 200;
                this.buildings++;   
                this.newYpos = 192;                                                                             // next building moves down 1 building length
            }
            else {
                //display message
                game.data.message= {msgTime: me.timer.getTime(), msg:"ENEMY Not enough Money", msgDur: 5, color:"red"};
            }
            console.log("Enemy is placing barracks, current gold: " + game.dataAI.playergold);
            this.isPlacing = false;
        //
        //     //What to do if building and type Armourer
        }else if (this.isPlacing == true && me.input.isKeyPressed("armourer")) {
        //
        //     //TODO: dynamically use cost of building instead of hardcoded "200"
            if(game.dataAI.playergold >= 200) {
                // Adding it to the world, at a place near the bounding box as set by the tiled map object
                me.game.world.addChild(new game.FootPrint((this.pos.x + this.width) / 4, (this.pos.y + this.height) / 4, {
                     width: 128,
                    height: 96,
                    bounds: this.bounds, // we'll need them from the box to determine if we can buiild at that postion
                    type: "armourer"
                }), 10);
                game.dataAI.playergold -= 200;
            }
            else {
                //display message
                game.data.message= {msgTime: me.timer.getTime(), msg:"Not enough Money", msgDur: 5, color:"red"};

            }
            console.log(game.data.playergold);
            this.isPlacing = false;

        }else if (this.isPlacing == true && me.input.isKeyPressed("arsenal")) {

            //TODO: dynamically use cost of building instead of hardcoded "200"
            if(game.dataAI.playergold >= 200) {
                // Adding it to the world, at a place near the bounding box as set by the tiled map object
                me.game.world.addChild(new game.FootPrint((this.pos.x + this.width) / 4, (this.pos.y + this.height) / 4, {
                    width: 150,
                    height: 150,
                    bounds: this.bounds, // we'll need them from the box to determine if we can buiild at that postion
                    type: "arsenal"
                }), 10);
                game.dataAI.playergold -= 200;
            }
            else {
                //display message
                game.data.message= {msgTime: me.timer.getTime(), msg:"Not enough Money", msgDur: 5, color:"red"};
        //
            }
//            console.log(game.data.playergold);
            this.isPlacing = false;
        }


        return this.selected || this.hover;
    },

    addStructure: function(structure){
        this.structures.push(structure);
    }

});

/**
 * BuildingObject is the starting point of any building
 * necessary for dragging and dropping of the footprint
 *
 */
game.BuildingObject = me.Entity.extend({
    /**
     * constructor
     */
    init: function (x, y, settings) {
        // ensure we do not create a default shape
        settings.shapes = [];
        // call the super constructor
        this._super(me.Entity, "init", [x, y, settings]);

        // status flags
        this.selected = false;
        this.hover = false;

        // to memorize where we grab the shape
        this.grabOffset = new me.Vector2d(0,0);

        this.body.setCollisionMask(me.collision.types.PLAYER_OBJECT);

        this.builder = settings.builder;                                                                                            // for enemy AI requires some special settings to function
        if (this.builder === "AI") {
            this.alwaysUpdate = true;
            this.goRight = true;
            this.goDown = false;
            this.goLeft = false;
            this.body.setVelocity(15,15);
        }

        this.player = settings.player;
    },

    onActivateEvent: function () {
        if (this.builder === "AI") {                                                                                                // if the builder is AI, control its thought process
            // maybe do something upon activation
        } else {
        //register on mouse/touch event
        me.input.registerPointerEvent("pointerdown", this, this.onSelect.bind(this));
        me.input.registerPointerEvent("pointerup", this, this.onRelease.bind(this));
        me.input.registerPointerEvent("pointercancel", this, this.onRelease.bind(this));
        //register locally...i think.
        me.input.registerPointerEvent('pointermove', this, this.pointerMove.bind(this));
        }
    },

    /**
     * pointermove function
     */
    pointerMove: function (event) {

        this.hover = false;
        //console.log(event.gameX, event.gameY);
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
            this.checkPosition();
            //console.log("position:",event.gameX, event.gameY,this.checkPosition() )
        }

        if (this.hover || this.selected) {
            return false;
        }
    },
    /*
     * Check the position  to not be over an existing structure
     */
    checkOtherBldg : function () {
        this.flag= false;
        this.factor = 0;
        for(i = 0; i < game.data.structures.length; i++) {
            if (((this.pos.x > game.data.structures[i]._width + game.data.structures[i].pos.x - this.factor) //all the way right
                || (this.pos.x+this.width - this.factor < game.data.structures[i].pos.x))// all the way left
                || (this.pos.y+this.height - this.factor < game.data.structures[i].pos.y)// the way above
                || (this.pos.y > game.data.structures[i].pos.y + game.data.structures[i]._height  - this.factor)){ // below

                this.flag = true;
            }
        }

        // it's fine if it's the first building or the flag is set
        if(this.flag || game.data.structures.length == 0){
            return true;
        }
        return false;
    },
    /*
     * Check the position  to be within the "build" area and updates the image
     */
    checkPosition : function () {
        //todo flesh this out so it also checks for entities in the way
        //console.log( this.bounds);

        if(this.pos.x > this.bounds.x
            && this.pos.x < this.bounds.width+this.bounds.x
            && this.pos.y > this.bounds.y
            && this.pos.y < this.bounds.height+this.bounds.y
            && this.checkOtherBldg()){
            //update the image
            this.chooseImage("good");

            return true;
        }else{
       //     console.log("not");
            this.chooseImage("bad");
        }
        return false;
    },
    // mouse down function
    onSelect : function (event) {
        if (this.hover === true) {
            this.grabOffset.set(event.gameX, event.gameY);
            this.grabOffset.sub(this.pos);
            console.log('selected');
            this.selected = true;
            // don"t propagate the event furthermore
            return false;
        }
        return true;
    },

    // mouse up function
    onRelease : function (/*event*/) {
        this.selected = false;

        //todo fix error from removal
        if(this.placeBuilding()){
            this.destroy();
        }
        // don"t propagate the event furthermore
        return false;
    },

    /**
     * update function
                 this.goRight = true;
            this.goDown = false;
            this.goLeft = false;
            this.scanFinished = false;
     */
    update: function (dt) {
        // only perform these actions if the builder was the AI
        if (this.builder == "AI") {
        // check position each update, if the position is OK, place the building
            if (this.checkPosition()) {
                if(this.placeBuilding()){
                    this.destroy();
                }
            }
            this.body.update(dt);

            if ((this.pos.x + (this.width) * 1.5) >= (this.bounds.width + this.bounds.x) && this.goRight == true) {                                                 // todo: double/recheck bounds later
                this.body.vel.x = 0;
                this.goRight = false;
                this.currentY = this.pos.y;
            }

            if (this.goRight == false && this.goDown == false) {
                this.body.vel.y += this.body.accel.y * me.timer.tick;
                if (this.currentY + 50 < this.pos.y) {                                                                                                              // go down ~50 pixels, then go left
                    this.goDown = false;
                    this.goLeft = true;
                    this.body.vel.y = 0;
                }
            }

            if (this.goLeft == true) {
                this.body.vel.x -= this.body.accel.x * me.timer.tick;
                if (this.pos.x <= this.bounds.x) {
                    this.body.vel.x = 0;
                    this.goLeft = false;
                    this.goRight = true;
                }
            }

            // final height check
            if (this.pos.y + this.height >= this.bounds.y + this.bounds.height) {
                this.goDown = false;
                this.goLeft = true;
                this.goRight = false;
                this.body.vel.y = 0;
                this.body.vel.x -= this.body.accel.x * me.timer.tick;
            }

            if (this.pos.x < this.bounds.x) {
                this.scanFinished = true;
                this.goDown = false;
                this.goLeft = false;
                this.goRight = false;
                this.body.vel.y = 0;
                this.body.vel.x = 0;
                me.game.world.removeChild(this);
                console.log("ENEMY BASE: no more space for buildings!");                                                                                            // debug message
            }

            // set movement
            if (this.builder == "AI" && this.goRight == true) {
                this.body.vel.x += this.body.accel.x * me.timer.tick;
            }

        }

    //    me.collision.check(this);

        return this.selected || this.hover;
    },

    /**
     * draw the square
     */
    draw: function (renderer) {
        renderer.setGlobalAlpha(this.hover ? 1.0 : 0.5);
        this._super(me.Entity, "draw", [renderer]);
        renderer.setGlobalAlpha(0.80);
    },
    destroy: function(){
        if (this.builder != "AI") {
            me.input.releasePointerEvent('pointerdown', this);
        }
        me.game.world.removeChild(this);
    },

    onCollision: function(response, other){
        console.log("i hit something");
        return false;
    }

});
/**
* footprint is determined by the parameters sent to it in the call from game.BuildingArea = me.Renderable.extend
* it extends the building object which contains all the drag a drop functions
*/
game.FootPrint = game.BuildingObject.extend({
    /**
     * constructor
     */
    init: function (x, y, settings) {
        // we want the foot print established by the settings from which was called.
        //settings.image =  "footprint-spritesheet";
        //console.log("the bloody settings!", settings);

        // call the super constructor
        this._super(game.BuildingObject, "init", [x, y, settings]);

        // the bounds of the Building Container
        this.bounds = settings.bounds;

        // add a body shape
        console.log("player",this.player);
        this.body.addShape(new me.Rect(0, 0, settings.width, settings.height));

        this.checkPosition();

        //use to the track if it has been placed
        this.placed = false;

        //fonts
        this.color = "green";
        this.font = new me.Font("Arial", 15, "black");
        this.font.textAlign = "left";
        this.font.bold();

        this.player = settings.player;

        this.body.setCollisionMask(me.collision.types.PLAYER_OBJECT);
    },
    /**
     * Change the image
     */
    chooseImage: function (frameName) {
        //this.renderable.setCurrentAnimation(frameName);
        switch(frameName){
            case "good":
                this.color = "green";
                break;
            case "bad":
                this.color = "red";
                break;
            default:

        }

    },
    /*
        This places the actual building of the specific type defined in the buildingArea call
     */
    placeBuilding: function (){

        //add building to the area.
        var bldg = null;


        //settings for the new building;
        var newBldg = {
            width: this.width,
            height: this.height,
            bounds: this.bounds,
            type: this.type,
            player: this.player
        };
        //console.log(newBldg);
        if(this.type == "barracks") {

            if (this.checkPosition()) {
                bldg = me.game.world.addChild(new game.Barracks(this.pos.x, this.pos.y, newBldg), 10);

                if (this.builder == "AI") {                                                                                                             // store into dataAI buildings when new building is built
                    game.dataAI.structures.push(bldg);
                    //console.log("ENEMY BUILDING ARRAY:");
                    // console.log(game.dataAI.structures);
                }else{
                    game.data.structures.push(bldg);
                    //console.log("structures",game.data.structures);
                }

                return true;
            }
        }
        if(this.type == "armourer") {
            if (this.checkPosition()) {
                bldg = me.game.world.addChild(new game.Armourer(this.pos.x, this.pos.y, newBldg), 10);

                if (this.builder == "AI") {                                                                                                             // store into dataAI buildings when new building is built
                    game.dataAI.structures.push(bldg);
                    // console.log("ENEMY BUILDING ARRAY:");
                    // console.log(game.dataAI.structures);
                }else{
                    game.data.structures.push(bldg);
                    console.log("structures",game.data.structures);
                }
                return true;
            }
        }
        if(this.type == "arsenal") {

            if (this.checkPosition()) {
               bldg =  me.game.world.addChild(new game.Arsenal(this.pos.x, this.pos.y, newBldg), 10);
                game.data.structures.push(bldg);

                if (this.builder == "AI") {                                                                                                             // store into dataAI buildings when new building is built
                    game.dataAI.structures.push(bldg);
                    // console.log("ENEMY BUILDING ARRAY:");
                    console.log("Enemy structure",game.dataAI.structures);
                }else{
                    game.data.structures.push(bldg);
                    console.log("structure",game.data.structures);
                }
                return true;
            }
        }
        return false;
    },
    draw: function (renderer) {
        renderer.setGlobalAlpha(0.5);
        renderer.setColor(this.color);
        renderer.fillRect(this.pos.x, this.pos.y, this.width, this.height);
        this.font.draw(renderer, this.type, this.pos.x, this.pos.y);
    }
});

game.Queue = me.Renderable.extend({
    init: function (x, y, settings) {

        this._super(me.Renderable, "init", [0, 0, me.game.viewport.width, me.game.viewport.height]);
        this.floating = true;
        this.pos.x = x;
        this.pos.y = y;
        this.width = settings.width;
        this.height = settings.height;
    }
});