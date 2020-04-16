using System;

namespace ConsoleApp1
{
    class Program
    {
        static int TestFN3(object str,params int[] args)
        {
            int a=0, i;
           

            for (i=0;i<args.Length;i++)
            {
                a += args[i];

              // if(i==0)
              //      Console.WriteLine("{0}{1}",args[i], str);
              // else if (i == 1)
              //     Console.WriteLine("{0}{1}", args[i], str);
              //else if (i == 2)
              //    Console.WriteLine("{0}{1}", args[i], str);
              // else if (i == 3)
              //    Console.WriteLine("{0}{1}", args[i],"=");           

                switch (i)
               {
                   case 0:
                        Console.WriteLine("{0}{1}", args[i], str);
                        break;
                    case 1:
                        Console.WriteLine("{0}{1}", args[i], str);
                        break;
                    case 2:
                        Console.WriteLine("{0}{1}", args[i], str);
                        break;
                    case 3:
                        if (i == 3)
                        {
                            Console.WriteLine("{0}{1}", args[i], "=");
                        }
                        break;
              }
            }
           
            return a;

        }
        static void Main(string[] args)
        {
           
            Console.WriteLine("{0}",TestFN3("+",10,20,30,40));
            
        }
    }
}



                   
