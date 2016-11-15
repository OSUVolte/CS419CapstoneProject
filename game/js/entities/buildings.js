

game.Structures = me.Entity.extend({
    /**
     * constructor
     */
    init: function (x, y, settings) {

        //load the general properties
        this.generalProperties();

        // call the super constructor
        this._super(me.Entity, "init", [x, y, settings]);
        this.body.setCollisionMask(me.collision.types.NO_OBJECT);
    },
    generalProperties: function(){
        this.q = [];
        this.allowBuild = false;
        this.complete = false;
    },
    onActivateEvent: function () {
        //register on mouse/touch event
        me.input.registerPointerEvent("pointerdown", this, this.onSelect.bind(this));
        me.input.registerPointerEvent("pointerup", this, this.onRelease.bind(this));
        me.input.registerPointerEvent("pointercancel", this, this.onRelease.bind(this));

        // register on the global pointermove event
        // If this causes issus see building_manager for alternative set up
        console.log("onActivate fired");
        this.handler = me.event.subscribe(me.event.POINTERMOVE, this.pointerMove.bind(this));
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
            //todo show a menu or status or something

        }

        if (this.hover || this.selected) {
            return false;
        }
    },

    // mouse down function
    onSelect : function (event) {
        if (this.hover === true) {
            // this.grabOffset.set(event.gameX, event.gameY);
            // this.grabOffset.sub(this.pos);
            console.log('selected the new buiding');
            this.selected = true;
            this.displayStatus();
            // don"t propagate the event furthermore
            return false;
        }
        return true;
    },

    // mouse up function
    onRelease : function (/*event*/) {
        this.selected = false;
        // close  building menu

        // don"t propagate the event furthermore
        return false;
    },
    /**
     * Spawns Units of specified type at objects location
     * @param type string of the unit type as defined Classes in Entities.js (i.e. "Warrior" but not "warrior")
     */
    spawnUnit: function(type){
        me.game.world.addChild(me.pool.pull("units", this.pos.x, this.pos.y, eval(type), {
            framewidth: 32,
            frameheight: 32,
            height: this.height,
            width: this.width,
            // direction
            lane: "top",
            qAssignment: this.activeQ, //the units queue assignment

            // which player spawned
            player: 1,
            shapes: [new me.Rect(0, 0, 32, 32)]
        }), 10); //todo not sure about z index
    },
    /**
     * Adds type of element to the Building Queue
     * @param type string of the entity type
     * Returnes true if added
     */
    addUnitQ: function(type){
        //an obj with the time it was added and the type of element
        var qObj = {
            time: new Date().getTime(),
            type: type
        };
        //don't add if it would go over capacity
        if(this.q.length + 1 <= this.capacity){
            this.q.push(qObj);
            return true;
        }
        return false;
    },
    /**
     * Removes a building element from the queue
     * @param index index to be removed from the queue
     */
    removeUnitQ: function(index){
        curLength = q.length;
        if(index+1 < this.capacity) {
            q.splice(index, 1);
        }
        //make sure it decreased by one
        return q.length == curLength - 1;
    },
    /**
     * Gets the Amount of time until the next Unit will spawn
     * @param q
     */
    tNext: function(q){


    },

    /**
     * Actions to be taken when the unit build is complete
     * @param dt the current time
     * @param cb a call back function of what's to be done when it's complete
     */
    unitComplete: function(ctime){
        var ubt = 100000;
        //only do this when when have units in the queue
        if(this.q.length > 0){

            //get the first units type
            var unit = this.q[0].type;

            //get the build time of the unit being built
            switch(unit){

                // case "Warrior":
                //     ubt = game.Warrior.buildTime;
                //     break;
                //todo Add all unit types
                default:
                    ubt = 10;
            }

            //console.log((ctime, ctime - this.q[0].time)/1000, ubt )
            //check if unit is complete
            if((ctime, ctime - this.q[0].time)/1000 >= ubt){
                //remove the first element in the queue
                this.q.shift();

                //spawn the unit
                console.log("spawning", unit.toLowerCase())
                this.spawnUnit(unit);
            }
        }
    },
    /**
     * update function
     */
    update: function () {
        //This is all handled by the sub or extending class
        //use mainUpate in each to call standard update functions
    },
    /**
     * Used to define functions that are a part of all buildings but would
     * be overridden by the extender's update function, i.e key presses
     * @param dt
     */
    mainUpdate: function(dt){

        this._super(me.Entity, "update", [dt]);
        var now = new Date().getTime();

        //add units to a building queue
        if (this.selected == true && me.input.isKeyPressed("makeType1")) {

            //only allow units when the building is ready to work
            if(this.complete) {
                if (this.addUnitQ("warrior")) {
                    console.log("Adding Unit");
                } else {
                    console.log("cannot add queue is full")
                }
            }else{
                console.log("building is not complete")
            }
        }else if (this.selected == true && me.input.isKeyPressed("makeType2")) {

            //only allow units when the building is ready to work
            if(this.complete) {
                if (this.addUnitQ("rogue")) {
                    console.log("Adding Unit");
                } else {
                    console.log("cannot add queue is full")
                }
            }else{
                console.log("building is not complete")
            }
        }else if (this.selected == true && me.input.isKeyPressed("makeType3")) {

            //only allow units when the building is ready to work
            if(this.complete) {
                if (this.addUnitQ("slime")) {
                    console.log("Adding Unit");
                } else {
                    console.log("cannot add queue is full")
                }
            }else{
                console.log("building is not complete")
            }
        }
        //Remove a Unit from the end of the queue
        if (this.selected == true && me.input.isKeyPressed("remove")) {
            //remove a unit from the end
            this.removeUnitQ(this.q.length-1);
            console.log("removing");

        }

        //spawn units when time is ready
        this.unitComplete(now);

        //log some state stuff
        if(me.input.isKeyPressed("log")){
            this.logitAll(dt);
        }

        return this._super(me.Entity, 'update', [dt]);
    },
    /**
     * Logging of some specific variables to help with trouble shooting
     */
    logitAll: function(dt){
        console.log("selected: ", this.selected);
        console.log("the queue", this.q);
        console.log("dt", dt);
        console.log();

    },

});

//todo set up collisions on buildings
game.Barracks = game.Structures.extend({
    /**
     * constructor
     */
    init:function (x, y, settings) {

        //call the constructor
        this._super(game.Structures, 'init', [x, y , settings]);
        this.x = x;
        this.y = y;
        this.placed = true;
        this.bldgProperties();
        this.body.addShape(new me.Rect(0,0, settings.width, settings.height));  // add a body shape
        this.renderable = new me.Sprite(0, 0, {image: me.loader.getImage("Barracks")}); //addimage
        console.log(this.x, this.y);
    },
    /**
     * Defines all the properties of the building
     *
     */
    bldgProperties: function(){

        this.buildTime = 30;
        this.percentComplete = 0;
        this.est = Math.round(new Date().getTime()/1000);
        this.functional = false; //starts off as non-functional until build time expires

        //the types of units that this building can build
        this.enabled = {
            type1:true,
            type2: false,
            type3: false  //' etc etc //todo add all unit types
        }; //
        this.upm = 5; //units per minute
        this.capacity = 5;
        this.health = 1000;
        this.cost = 200; //cost for barracks is 500 gold
        this.activeQ = 0; // default is the front
    },
    /**
     * Change the image
     */
    chooseImage: function () {
        //todo make it update its color depending on status (healthy, damaged, working, tobe destroyed etc)
        //this.renderable.addAnimation("building", [0], 5);
        //this.renderable.setCurrentAnimation("neutral");
    },
    /**
     * Set spawn point of the footprint
     * Might want to make it relative to some other entity
     */
    setSpawnPoint : function (dt) {
        //todo make this useable
        //It might be best to offset this point from the buildings - but it will need a check to make sure
        //it doesn't interfere with other buildings...
    },
    /**
     * update the entity
     */
    update : function (dt) {
        //Update functions of our game objects will always receive a delta time (in milliseconds).
        // It's important to pass it along to our parent's class update.
        //setting the time for the building
        this._super(me.Entity, "update", [dt]);

        //mainUpdate - General functions that are good for all buildings
        this.mainUpdate(dt);

        //establish time elapsed since the placement
        this.now = Math.round(new Date().getTime()/1000);
        this.elapsed = this.now - this.est;

        //establish a percent complete
        if(this.elapsed < this.buildTime) {
            this.percentComplete = Math.round(( this.elapsed/this.buildTime)*100);
        }else{
            this.percentComplete = 100;
        }

        //do something when its placed
        if(this.placed){

            //start construction
            if(this.elapsed > this.buildTime){
                this.complete = true;
                //console.log("buildingAllowed", true);
                //this.chooseImage();//update the image when complete
            }
        }
        return this._super(me.Entity, "update", [dt]);
    },
    /**
     * collision handler
     * (called when colliding with other objects)
     */
    onCollision : function (response, other) {
        // Make all other objects solid
        return true;
    },
    displayStatus: function(){
        this.panel = me.game.world.addChild(new game.UI.BuildingStatus(this.x, this.y,  400, 300, "Barracks Menu", this));

        if(this.enabled.type1){
            this.panel.addChild(new game.UI.UnitAdd(
                20, 40,
                "yellow",
                "Add Warrior",
                "warrior"// default
            ),110);
        }
        if(this.enabled.type2) {
            this.panel.addChild(new game.UI.UnitAdd(
                20, 90,
                "green",
                "Add Slime", // default
                "slime"
            ), 110);
        }
        if(this.enabled.type3) {
            this.panel.addChild(new game.UI.UnitAdd(
                20, 140,
                "blue",
                "Add Rogue", // default
                "rogue"
            ), 110);
        }

       //Generate 3 buttons for 3 queues
       for(i=0; i < 3; i++){
           this.addQueueButtons(this.activeQ,i)
       }


        //add the new buttons to a group so that we can track which is currently active
        //and use this to set behaviors and change the display
    },
    addQueueButtons: function (aq, index){
        var xCoor = 93+(70*index);
        var img = "reg"+index;
        //change the image depending if the button is the active queue
        if(aq == index){
            img = "reg"+index+"Pushed";
        }
        this.panel.addChild(new game.UI.QueueSelector(
            xCoor, 180,
            img, //img name
            "", // default
            index, // index of this button
            this.activeQ
        ), 110);
    }

});







