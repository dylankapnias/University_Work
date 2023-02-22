/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package up.practical_1;

import java.io.Serializable;
import javax.persistence.*;

/**
 *
 * @author Dylan Kapnias (u18108467)
 */

@Entity
public class Student implements Serializable {
    //The serialVersionUID is a universal version identifier for a Serializable class
    private static final long serialVersionUID = 1L;
    //This annotation specifies the primary key of the entity
    @Id
    private String student_number;
    
    private String first_name;
    private String last_name;
    private String degree_name;
    
    public Student() {
        first_name = "";
        last_name = "";
        degree_name = "";
        student_number = "u00000000";
    }
    
    public Student(String f, String l, String d, String s) {
        first_name = f;
        last_name = l;
        degree_name = d;
        student_number = "".equals(s) ? "u00000000" : s;
    }
    
    public String get_sno() {
        return student_number;
    }
   
    public String get_fname() {
        return first_name;
    }
    
    public String get_lname() {
        return last_name;
    }
    
    public String get_dname() {
        return degree_name;
    }
    
    public void set_fname(String s) {
        first_name = s;
    }
    
    public void set_lname(String s) {
        last_name = s;
    }
    
    public void set_dname(String s) {
        degree_name = s;
    }
    
    @Override
    public String toString() {
        return String.format("(First Name: %s, Last Name: %s, Degree Name: %s, Student Number: %s)", this.first_name, this.last_name, this.degree_name, this.student_number);
    }
}
