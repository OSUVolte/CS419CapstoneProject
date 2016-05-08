public void testIsValid(Object[] testObjects, long options) {
      //create URL Validator object url val with parameters schemes set as null and RegexValidator authority validator set as null and 
      //the Allow2Slashes, allow all schems and no fragments options selected
      UrlValidator urlVal = new UrlValidator(null, null, options);
      //calls isValid using validator isValid function for two known valid urls
      assertTrue(urlVal.isValid("http://www.google.com"));
      assertTrue(urlVal.isValid("http://www.google.com/"));
      //preset printed and status per line
      int statusPerLine = 60;
      int printed = 0;
      //print index that indicates current scheme,host,port,path, query test were using. Set as 
      //false in URLValidator test class
      if (printIndex)  {
         statusPerLine = 6;
      }
      //do while loop
      do {
         //create stringbuffer objet
         StringBuffer testBuffer = new StringBuffer();
         //set expected to ture
         boolean expected = true;
         //uses testPartsIndexIndex as looping variable while less than testPartsIndex.length
         //initialized in setUp() functions
         for (int testPartsIndexIndex = 0; testPartsIndexIndex < testPartsIndex.length; ++testPartsIndexIndex) {
            //set index variable
            int index = testPartsIndex[testPartsIndexIndex];
            //creates ResultPair array part from ResultPair object which groups tests and expected results
            //http://grepcode.com/file/repo1.maven.org/maven2/commons-validator/commons-validator/1.4.1/org/apache/commons/validator/ResultPair.java
            //public class ResultPair {
            //public String item;
            //public boolean valid;

            //public ResultPair(String item, boolean valid) {
                  //this.item = item;
                  //this.valid = valid;  //Weather the individual part of url is valid.
               //}
            //}
            ResultPair[] part = (ResultPair[]) testObjects[testPartsIndexIndex];
            //appends item from result pair to test buffer
            testBuffer.append(part[index].item);
            //makes expected = expected and part[index].valid...expected set to true earlier
            expected &= part[index].valid;
         }
         //System.out.println(testPartsIndex[0]);
         //changes items from previous parts of constructed url to a string
         String url = testBuffer.toString();
         //tests string to see if it is a valid url
         boolean result = urlVal.isValid(url);
         //if valid print url
         if(result == true)
        	 System.out.println(url);
         //asserts that url is valid, expected and part[index].valid is true and that result exists
         assertEquals(url, expected, result);
         //if printstatus is true (set as false in URL validator test move on)
         if (printStatus) {
            //if print index is true, move on
            if (printIndex) {
               //System.out.print(testPartsIndextoString());
            } else {
               //check if result == expected and print a period
               if (result == expected) {
                  System.out.print('.');
               } else {
                  //if result is not expected print an X
                  System.out.print('X');
               }
            }
            //increment printed
            printed++;
            //check if the printed int == statusPerLine which is either 60 or 6 then println and change printed back to zero
            if (printed == statusPerLine) {
               //output new line
               System.out.println();
               printed = 0;
            }
         }
         //move to next url 
      } while (incrementTestPartsIndex(testPartsIndex, testObjects));
      //print a new line
      if (printStatus) {
         System.out.println();
      }
   }