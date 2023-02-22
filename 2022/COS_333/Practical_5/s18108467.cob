       IDENTIFICATION DIVISION.
       FUNCTION-ID. readData.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
           01 i PIC 9(1) VALUE 1.
           01 inVal PIC 9(4) VALUE ZEROS.
       LINKAGE SECTION.
           01 inArr.
               02 Vals PIC S9(4) VALUES ZEROS OCCURS 5 TIMES.
           01 outInt PIC X(3) VALUE ZEROS.
       PROCEDURE DIVISION USING BY REFERENCE inArr RETURNING outInt.
       startPara.
           PERFORM inData WITH TEST AFTER UNTIL i > 5.
           MOVE 1 TO outInt.
           GOBACK.
       inData.
           DISPLAY "Please insert a number".
           ACCEPT inVal.
           MOVE inVal TO Vals(i).
           ADD 1 TO i.
       END FUNCTION readData.
       IDENTIFICATION DIVISION.
       FUNCTION-ID. stdDev.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
           01 i PIC 9(1) VALUE 1.
           01 meanVal PIC 9(4)V9(2) VALUE ZEROS.
           01 devVal PIC 9(4)v9(2) VALUE ZEROS.
       LINKAGE SECTION.
           01 inArr.
               02 Vals PIC S9(4) VALUES ZEROS OCCURS 5 TIMES.
           01 outVal PIC 9(4)v9(2) VALUE ZEROS.
       PROCEDURE DIVISION USING BY REFERENCE inArr RETURNING outVal.
       startPara.
           PERFORM meanCalc WITH TEST AFTER UNTIL i > 5.
           MOVE 1 TO i.
           DIVIDE meanVal BY 5 GIVING meanVal.
           GO TO devStart.
       meanCalc.
           ADD Vals(i) TO meanVal
           ADD 1 TO i.
       devStart.
           PERFORM devCalc WITH TEST AFTER UNTIL i > 5.
           MOVE 1 TO i.
           GO TO finalStart.
       devCalc.
           SUBTRACT meanVal FROM Vals(i) GIVING Vals(i).
           MULTIPLY Vals(i) BY Vals(i) GIVING Vals(i).
           ADD 1 TO i.
       finalStart.
           PERFORM finalCalc WITH TEST AFTER UNTIL i > 5.
           DIVIDE devVal BY 5 GIVING devVal.
           COMPUTE devVal = devVal ** 0.5.
           MOVE devVal TO outVal.
           GOBACK.
       finalCalc.
           ADD Vals(i) TO devVal.
           ADD 1 TO i.
       END FUNCTION stdDev.
       IDENTIFICATION DIVISION.
       PROGRAM-ID. 's18108467'.
       ENVIRONMENT DIVISION.
       CONFIGURATION SECTION.
       REPOSITORY.
       FUNCTION readData
       FUNCTION stdDev.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 workArr.
               02 Vals PIC S9(4) VALUE ZEROS OCCURS 5 TIMES.
       01 check PIC 9 VALUE ZEROS.
       PROCEDURE DIVISION.
       
       COMPUTE check = readData(workArr).
       DISPLAY "Std. Dev: " stdDev(workArr).
       
       GOBACK.
       END PROGRAM 's18108467'.
