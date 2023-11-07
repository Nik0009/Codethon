
package app;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

class Student {
    private String name;
    private int prnNo;

    @Override
    public String toString() {
        return "Student{" + "name=" + name + ", prnNo=" + prnNo + '}';
    }
     public Student(String name, int prnNo) {
        this.name = name;
        this.prnNo = prnNo;
    }
    public Student() {}
    
}

class Trainer{
    private String name;

    public Trainer(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Trainer{" + "name=" + name + '}';
    }
    
}

class Assignment{
    private String title;
    private  String date;
    private String description;
    private String assignee;
    
    private Student s;
    private Trainer t;

     public Assignment(String title, String date, String description, String assignee) {
        this.title = title;
        this.date = date;
        this.description = description;
        this.assignee = assignee;
        
    }
    
    public Assignment(String title, String date, String description, String assignee, Student s, Trainer t) {
        this.title = title;
        this.date = date;
        this.description = description;
        this.assignee = assignee;
        this.s = s;
        this.t = t;
    }
    public Assignment(){}

    void  AssignmentDetails(){
        System.out.println("tile:"+title);
        System.out.println("date:"+date);
        System.out.println("description:"+description);
        System.out.println("assignee:"+assignee);
        System.out.println("tile:"+s);
        System.out.println("tile:"+t);
    }
 
    
}

public class AssignmentManager {
    Scanner sc=new Scanner(System.in);
    
    void createAssignment(){
//        Student student=new Student();
//        Trainer trainer=new Trainer();
        
        System.out.println("Create Assignment");
        System.out.println("Enter title:");
        String t=sc.nextLine();
        System.out.println("Enter date:");
//        Date d=new Date();
        String sDate=sc.nextLine();       
//        SimpleDateFormat sdf=new SimpleDateFormat("yyyy-MM-dd ");
//        try{
//        Date dt=sdf.parse(sDate);
//        //System.out.println(dt);
//        }
//        catch(Exception e)
//        {
//            System.out.print(e);  
//        }        
        System.out.println("Enter Description:");
        String desc=sc.nextLine();       
        System.out.println("Enter trainer to assignee:");
        String assign=sc.nextLine();       
         
        Assignment a=new Assignment(t,sDate,desc,assign);  
        a.AssignmentDetails();
    }
    
    void addAssignment(){
        
        
//        List<Student> lst=new ArrayList<Student>();
        
        Scanner sc=new Scanner(System.in);
        System.out.println("add ");
        System.out.println("enter student name:");
        String name=sc.nextLine();
        System.out.println("enter student prn:");
        int prn=sc.nextInt();
        Student student=new Student(name,prn);
//        lst.add(student);
        Student s=new Student(name,prn);
        
        
        System.out.println("enter trainer name:");
        String namet=sc.nextLine();
        Trainer trainer=new Trainer(namet);
        
          
       
        
    }
    void showAssignment(){
       Assignment a=new Assignment();
       a.AssignmentDetails();
    }
    
    void saveAssignment(){
        try {
            Path path = Paths.get("C:\\CDAC\\Class Works\\JAVA TEST 07.11.2023\\text.txt");
           Assignment a=new Assignment();
            String content;
            content = a.toString();
           
           
            
            for(int i=0;i<5;i++)
                Files.write(path,content.getBytes(),StandardOpenOption.APPEND);
            
            
            System.out.println("sucessfully save in a file");

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
    void loadAssignment(){
         try{
            Path path=Paths.get("C:\\CDAC\\Class Works\\JAVA TEST 07.11.2023\\test.txt");
            List<String> lst=Files.readAllLines(path);
            for(String str:lst){
                System.out.println(str);
            }
            
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
    }
    void chkAssigment(){
        
    }
    
    
    
    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        do{
        System.out.println("\t\t\tCDAC ASSIGNMENT MANAGEMENT:-");
        System.out.println("\t\t\t1.Create Assignment\n\t\t\t2.Add Assignment\n\t\t\t3.Show Assignment\n\t\t\t4.Save Assignment\n\t\t\t5.Load Assignment\n\t\t\t6.Check Assignmrnt on basis of Date");
        System.out.println("\t\t\tEnter Any one option from above:-");
         int n=sc.nextInt();
        
        AssignmentManager a=new AssignmentManager();
        
        switch(n){
            case 1:
                a.createAssignment();
                break;
            case 2:
                a.addAssignment();
                break;
            case 3:
                a.showAssignment();
                break;
            case 4:
                a.saveAssignment();
                break;
            case 5:
                a.loadAssignment();
                break;
            case 6:
                a.chkAssigment();
                break;
            
            
            
            default:
                System.out.println("Please enter correct option between (1-5) !!!!!");
        }
        }while(true);
        }
    
}
