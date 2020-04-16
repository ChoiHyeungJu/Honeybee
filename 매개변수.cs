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
    //교수님 일단 어떻게 만들어보긴 했는데 
}//이런식으로 이미 써져있는것을 출력하는건가요? 아니면 c에서 scanf쓰는것처럼 입력하면 출력하도록 하는건가요??



                   