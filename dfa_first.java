package cd;

import java.util.*;

public class dfa_first {
	
	static String[] states = new String[10]; //states in the dfa
	
	static HashMap<String, String> transition_a = new HashMap<String, String>();
	static HashMap<String, String> transition_b = new HashMap<String, String>();
	
	int n; //no. of states
	
	static void string_processing(String initial_state, String final_state)
	{
		System.out.println("Enter the string to check its acceptance by the dfa");
		Scanner sc1=new Scanner(System.in);
		String input=sc1.nextLine();
		int length = input.length();
		
		String start=initial_state;
		String process=start;
		String end=final_state;
		//System.out.print("->");
		for (int i=0;i<length;i++)
		{
			if(input.charAt(i)=='a')
			{
				System.out.print("("+process+",a)->");
				process= transition_a.get(process);
				System.out.println(process);
			}
			else if(input.charAt(i)=='b')
			{
				System.out.print("("+process+",b)->");
				process= transition_b.get(process);
				System.out.println(process);
			}
			else
			{
				process="String rejected";
			}
		}
		
		if(process.equals(end))
		{
			System.out.println("String accepted");
		}
		else if(process.equals("String rejected"))
		{
			System.out.println("Invalid String");
		}
		else
		{
			System.out.println("The string is not accepted");
		}
	}
	
	static void print_table(int n, String init, String fina)
	{
        System.out.println("The transition table will be");
		
		System.out.println("     |  a  |  b  |");
		System.out.println("_____|_____|_____|");
		for(int i=0;i<n;i++)
		{
				if(states[i]==init)
				{
					System.out.println("->"+states[i]+" |  "+transition_a.get(states[i])+" |  "+transition_b.get(states[i])+" |");
				}
				else if(states[i]==fina)
				{
					System.out.println(" *"+states[i]+" |  "+transition_a.get(states[i])+" |  "+transition_b.get(states[i])+" |");
				}
				else
				{
					System.out.println("  "+states[i]+" |  "+transition_a.get(states[i])+" |  "+transition_b.get(states[i])+" |");
			    }
				System.out.println("_____|_____|_____|");
		}
		
	}
		
	static void specific_substring()
	{
		int n=3;//no of states
		states[0]="q0";
		states[1]="q1";
		states[2]="q2";
		String initial_state=states[0];
		String final_state=states[n-1];
		
		transition_a.put(states[0],states[1]);
		transition_b.put(states[0],states[0]);
		transition_a.put(states[1],states[1]);
		transition_b.put(states[1],states[2]);
		transition_a.put(states[2],states[2]);
		transition_b.put(states[2],states[2]);
		
		print_table(n,initial_state,final_state);
	    string_processing(initial_state,final_state);
	}
	
	static void suffix()
	{
        int n=3;//no of states
		states[0]="q0";
		states[1]="q1";
		states[2]="q2";
		String initial_state=states[0];
		String final_state=states[n-1];
		
		transition_a.put(states[0],states[1]);
		transition_b.put(states[0],states[0]);
		transition_a.put(states[1],states[1]);
		transition_b.put(states[1],states[2]);
		transition_a.put(states[2],states[1]);
		transition_b.put(states[2],states[0]);
		
		print_table(n,initial_state,final_state);
		string_processing(initial_state,final_state);
		
	}
	
	static void prefix()
	{
        int n=4;//no of states
		states[0]="q0";
		states[1]="q1";
		states[2]="q2";
		states[3]="q3";
		String initial_state=states[0];
		String final_state=states[n-1];
		
		transition_a.put(states[0],states[1]);
		transition_b.put(states[0],states[2]);
		transition_a.put(states[1],states[2]);
		transition_b.put(states[1],states[3]);
		transition_a.put(states[2],states[2]);
		transition_b.put(states[2],states[2]);
		transition_a.put(states[3],states[3]);
		transition_b.put(states[3],states[3]);
		
		print_table(n,initial_state,final_state);
		string_processing(initial_state,final_state);
	}
	
	static void exactly()
	{
        int n=3;//no of states
		states[0]="q0";
		states[1]="q1";
		states[2]="q2";
		String initial_state=states[0];
		String final_state=states[1];
		
		transition_a.put(states[0],states[1]);
		transition_b.put(states[0],states[0]);
		transition_a.put(states[1],states[2]);
		transition_b.put(states[1],states[1]);
		transition_a.put(states[2],states[2]);
		transition_b.put(states[2],states[2]);
		
		print_table(n,initial_state,final_state);
		string_processing(initial_state,final_state);
		
	}
	
	static void atleast()
	{
        int n=3;//no of states	
		states[0]="q0";
		states[1]="q1";
		states[2]="q2";
		String initial_state=states[0];
		String final_state=states[2];
		
		transition_a.put(states[0],states[0]);
		transition_b.put(states[0],states[1]);
		transition_a.put(states[1],states[1]);
		transition_b.put(states[1],states[2]);
		transition_a.put(states[2],states[2]);
		transition_b.put(states[2],states[2]);
			
		print_table(n,initial_state,final_state);
		string_processing(initial_state,final_state);
	}
	
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		
		System.out.println("Select the type of DFA you want to construct: ");
		System.out.println("1.contains a specific substring ab");
		System.out.println("2.starting with a specified substring ab(prefix)");
		System.out.println("3.ending with a specified substring ab(suffix)");
		System.out.println("4.containing exactly a specified length of string(exactly one a)");
		System.out.println("5.containg atleast a specified length of string(atleast two b's)");
		
		int type=sc.nextInt();
		
		switch(type)
		{
		case 1:
			System.out.println("Constructing a DFA with ab as substring");
            System.out.println("No. of states = 3");  
            specific_substring();
            break;     
		case 2:
			System.out.println("Constructing a DFA that starts with ab");
            System.out.println("No. of states = 4");
            prefix();
            break;  		
		case 3:
			System.out.println("Constructing a DFA that ends with ab");
            System.out.println("No. of states = 3"); 
            suffix();
            break;	
		case 4:
			System.out.println("Constructing a DFA containing exactly one a");
            System.out.println("No. of states = 3"); 
            exactly();
            break;
		case 5:
			System.out.println("Constructing a DFA containing atleast 2 b's");
            System.out.println("No. of states = 3"); 
            atleast();
            break;    
		default:
			System.out.println("No such option available");
		}
	}
}