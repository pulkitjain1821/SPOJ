using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ABSYS
{
    class Program
    {
        public static int Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            Console.ReadLine();
            for (int i = 0; i < t; i++)
            {
                string line = Console.ReadLine();
                Console.ReadLine();
                string[] arr = line.Split(new char[] { '+', '=' });
                arr[0] = arr[0].Trim();
                arr[1] = arr[1].Trim();
                arr[2] = arr[2].Trim();
                long n = 0;
                bool a0 = long.TryParse(arr[0], out n);
                bool a1 = long.TryParse(arr[1], out n);
                bool a2 = long.TryParse(arr[2], out n);

                if (a0 == false)
                { 
                        Console.WriteLine("{0} + {1} = {2}", long.Parse(arr[2]) - long.Parse(arr[1]), arr[1], arr[2]);
                }
                else if (a1 == false)
                {
                        Console.WriteLine("{0} + {1} = {2}", arr[0], long.Parse(arr[2]) - long.Parse(arr[0]), arr[2]);
                }
                else
                {
                        Console.WriteLine("{0} + {1} = {2}", arr[0],arr[1], long.Parse(arr[0]) + long.Parse(arr[1]));
                }
            }
            return 0;
        }
    }
}
