using System;

public class hello
{
    #region input file
    public static string input = @"D:\CSharp\ConsoleTest\input.txt";
    public static int lineCounter = 0;
    public static string[] lines;
    public static string ReadLine()
    {
        if (!System.IO.File.Exists(input))
            return Console.ReadLine();
        if (lines == null)
        {
            lines = System.IO.File.ReadAllLines(input);
            lineCounter = 0;
        }
        if (lines == null) return "";
        return lines[lineCounter++];
    }
    #endregion

    static void Main()
    {
        main();
        #region stop console
        if (System.IO.File.Exists(input))
            Console.ReadKey();
        #endregion
    }

    public static void main()
    {
        var t = int.Parse(ReadLine());
        while (t-- > 0)
        {
            var n = int.Parse(ReadLine());
            var s = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            var sort = s.ToArray();
            Array.Sort(sort);
            List<int> result = new List<int>();
            for (int i = 0; i < n; i++)
            {
                if (s[i] != sort[n - 1])
                {
                    result.Add(s[i] - sort[n - 1]);
                }
                else
                {
                    result.Add(s[i] - sort[n - 2]);
                }
            }
            Console.WriteLine(string.Join(" ", result));
        }
    }
}