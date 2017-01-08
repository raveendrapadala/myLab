/***********************************************************************************
Through this example, i would like to cover declarations of type structures,
inheritance
***********************************************************************************/
package main

import (
	"fmt"
)

/*
 * This employee structure has no members but one method is there
 */
type employee struct{
	name string
	groupName string
 }
 
/*
 * Based on the designation, Returns true if he is from technical domain else false
 */
 func (e employee) isProductGroup(group string) (bool){
    if(group == "ProductGroup"){
      return true
      }else{
      return false
      }
  }
/*
 * Assumes all the elements of the struct employee
 */
type softwareEmployee struct{
	employee
	badgeId	int
	designation string
}

func main() {
	//Inheritance
	var mydetails = softwareEmployee{ employee{"Raveendra", "ProductGroup"}, 619406, "platformSoftwareSeniorEngineer"}
	/*
	   // true inheritance is not allowed in the typesystem of Go
	   var mydetails employee
	   //RHS, employee type where as LHS has softwareEmployee type, attracts error, cannot use softwareEmployee literal (type softwareEmployee) as type employee in assignment
	   mydetails = softwareEmployee{ employee{"Raveendra", "ProductGroup"}, 619406, "platformSoftwareSeniorEngineer"}
	
	*/
	
	fmt.Println("Do i belong to Product Group?", mydetails.isProductGroup("ProductGroup"))
}
