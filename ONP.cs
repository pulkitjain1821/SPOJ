using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Collections;
using System.Text;
using System.Linq;
namespace postfix
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            Char [][] str = new Char[n][];
            for (int k = 0; k < n; k++)
            {str[k]=ToPostfix(Console.ReadLine());
            }
            for (int k = 0; k < str.Length; k++)
            {
                for (int i = 0; i < str[k].Length; i++)
                    Console.Write(str[k][i]);
                Console.WriteLine();
            }  
            
        }
        public static Char[] ToPostfix(String inp)
        {

            Char[] infix = convToArray(inp);
            Char[] outs = new Char[infix.Length]; int ptr = 0;
            Stack temp = new Stack();
            Char c;
            for (int i = 0; i < infix.Length; i++)
            {
                c = infix[i];

                if (isOperator(c))
                {
                    while (!(temp.Count == 0) && (Char)temp.Peek() != '(')
                    {
                        if (OpGreaterOrEqual((Char)temp.Peek(), c))
                        { outs[ptr] = (Char)temp.Pop(); ptr++; }
                        else
                            break;
                    }
                    temp.Push(c);
                }
                else if (c == '(')
                    temp.Push(c);
                else if (c == ')')
                {
                    while (!(temp.Count == 0) && (Char)temp.Peek()!= '(')
                    {
                        outs[ptr] = (Char)temp.Pop(); ptr++;
                    }
                    if (!(temp.Count == 0))
                        temp.Pop();
                }
                else if (isOperand(c))
                { outs[ptr] = (c); ptr++; }


            }
            while (!(temp.Count == 0))
            {
                outs[ptr] = (Char)temp.Pop(); ptr++;
            }

            Char[] final_res = new Char[ptr];
            for (int z = 0; z < ptr; z++)
                final_res[z] = outs[z];
            return final_res;
        }

        public static Char[] convToArray(String expr)
        {


            Char[] exaray = new Char[expr.Length]; int j = 0;
            for (int i = 0; i < expr.Length; )
            {
                if (expr[i] == '(' || expr[i] == ')' || expr[i] == '*' || expr[i] == '+' || expr[i] == '-' || expr[i] == '/' || expr[i] == '^')
                {
                    exaray[j] = expr[i]; j++; i++;
                }

                
                else
                    if (expr[i] == ' ')
                        i++;
                    else if (Char.IsLetter(expr[i]))
                    { exaray[j] =expr[i]; j++; i++; }



            }
            Char[] corr = new Char[j];

            for (int i = 0; i < j; i++)
                corr[i] = exaray[i];

            return corr;

        }


        public static Boolean isOperator(Char c)
        {
            if (c == '+' || c == '/' || c == '-' || c == '*' || c == '^')
                return true;
            else
                return false;
        }
        public static Boolean isOperand(Char c)
        {
            
            if (Char.IsLetter(c))
                return true;
            else
                return false;
        }
        public static Boolean OpGreaterOrEqual(Char op1, Char op2)
        {
            /*return true if op1 has a greater prioroty over op2*/
            return (prec(op1) >= prec(op2));
        }

        public static int prec(Char op)
        {
            if (op=='+')
                return 0;
            else if (op=='-')
                return 1;
            else if (op=='*')
                return 2;
            else if (op=='/')
                return 3;
            else
                return 4;
        }
    }
}


