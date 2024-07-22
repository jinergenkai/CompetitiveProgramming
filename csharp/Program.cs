using System;
using System.Linq;
using CompLib.Util;
using System.Threading;
using System.IO;

#region Scanner
namespace CompLib.Util
{
    using System;
    using System.Linq;

    class Scanner
    {
        #region input file
        public static string input = @"D:\CSharp\ConsoleTest\input.txt";
        public static int lineCounter = 0;
        public static string[] lines;
        public static string ReadLineOfFile()
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

        private string[] _line;
        private int _index;
        private const char Separator = ' ';

        public Scanner()
        {
            _line = new string[0];
            _index = 0;
        }

        public Scanner(string s)
        {
            _line = new []{s};
            _index = 0;
        }

        public string Next()
        {
            if (_index >= _line.Length)
            {
                string s;
                do
                {
                    s = ReadLineOfFile();
                } while (s.Length == 0);

                _line = s.Split(Separator);
                _index = 0;
            }

            return _line[_index++];
        }

        public string ReadLine()
        {
            _index = _line.Length;
            return ReadLineOfFile();
        }

        public int NextInt() => int.Parse(Next());
        public long NextLong() => long.Parse(Next());
        public double NextDouble() => double.Parse(Next());
        public decimal NextDecimal() => decimal.Parse(Next());
        public char NextChar() => Next()[0];
        public char[] NextCharArray() => Next().ToCharArray();

        public string[] Array()
        {
            string s = ReadLineOfFile();
            _line = s.Length == 0 ? new string[0] : s.Split(Separator);
            _index = _line.Length;
            return _line;
        }

        public int[] IntArray() => Array().Select(int.Parse).ToArray();
        public long[] LongArray() => Array().Select(long.Parse).ToArray();
        public double[] DoubleArray() => Array().Select(double.Parse).ToArray();
        public decimal[] DecimalArray() => Array().Select(decimal.Parse).ToArray();
    }
}
#endregion

public class Program
{

    public static string input = @"D:\CSharp\ConsoleTest\input.txt";
    public static void Main()
    {
        var sc = new Scanner();
        var t = 1;
        // t = sc.NextInt();
        while (t-- > 0)
        {
            main();
        }
        #region stop console
        if (System.IO.File.Exists(input))
            Console.ReadKey();
        #endregion
    }

    public static void main()
    {
        // var sc = new Scanner("");
        String str = "<div>sad sad</div><div><p>das das</h></div>";

        bool inTag = false;
        String tagName = "";
        var map = new Dictionary<string, int>();

        for (int i = 0; i < str.Length; i++)
        {
            if (str[i] == '<') {
                inTag = true;
                continue;
            }
            else if (str[i] == '>') {
                inTag = false;
                if (!string.IsNullOrEmpty(tagName)) {
                    map[tagName] = !map.ContainsKey(tagName) ? i : (map[tagName] > 0 ? 0 : i + 1);
                    // Console.WriteLine(tagName);
                    tagName = "";
                }
                continue;
            }
            if (inTag) {
                if (str[i] != '/')
                    tagName += str[i];
            }
        }
        //for my map sort by value
        foreach (var item in map.OrderBy(x => x.Value))
        {    
            if (item.Value != 0) {
                Console.WriteLine(item.Key);
                return;
            }
        }
        Console.WriteLine("Empty");
    }

}
