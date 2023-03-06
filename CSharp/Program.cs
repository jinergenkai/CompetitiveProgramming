using System;
using System.Linq;
using CompLib.Util;
using System.Threading;
using System.IO;
using CSharp.Test;

using System.Collections.Generic;
using System.Threading.Tasks;

namespace CSharp.Test
{
    public class Blossom
    {
        int n, m;
        List<int> mate;
        List<int> p, d, bl;
        List<List<int>> b, g;

        public Blossom(int n) {
            this.n = n;
            m = n + n / 2;
            mate = Enumerable.Repeat(-1, n).ToList();

			// b = Enumerable.Repeat(new List<int>(), m).ToList();
			b = new List<List<int>>();
			for (int i = 0; i < m; i++)
				b.Add(new List<int>());

            p = Enumerable.Repeat(0, m).ToList();
            d = Enumerable.Repeat(0, m).ToList();
            bl = Enumerable.Repeat(0, m).ToList();

			// g = Enumerable.Repeat(Enumerable.Repeat(-1, m).ToList(), m).ToList();
			g = new List<List<int>>();
			for (int i = 0; i < m; i++)
				g.Add(Enumerable.Repeat(-1, m).ToList());

        }

        public List<int> GetMate() {
            return mate;
        }

        public void AddEdge(int u, int v) {
            g[u][v] = u;
            g[v][u] = v;
        }

        public void Match(int u, int v) {
            g[u][v] = g[v][u] = -1;
            mate[u] = v;
            mate[v] = u;
        }

        public List<int> Trace(int x) {
            var vx = new List<int>();
            while(true) {
                while(bl[x] != x) x = bl[x];
                if (vx.Any() && vx.Last() == x) break;
                vx.Add(x);
                x = p[x];
            }
            return vx;
        }

        public void Contract(int c, int x, int y, List<int> vx, List<int> vy) {
            this.b[c].Clear();
            int r = vx.Last();
            while(vx.Any() && vy.Any() && vx.Last() == vy.Last()) {
                r = vx.Last();
                vx.RemoveAt(vx.Count - 1);
                vy.RemoveAt(vy.Count - 1);
            }
            b[c].Add(r);

            b[c].AddRange(vx.AsEnumerable().Reverse());
            b[c].AddRange(vy);

            for (int i = 0; i <= c; i++) {
                g[c][i] = g[i][c] = -1;
            }

            foreach (var z in b[c]) {
                bl[z] = c;
                for (int i = 0; i < c; i++) {
                    if (g[z][i] != -1) {
                        g[c][i] = z;
                        g[i][c] = g[i][z];
                    }
                }
            }
        }

        public List<int> Lift(List<int> vx) {
            var A = new List<int>();
            while(vx.Count >= 2) {
                var z = vx.Last();
                vx.RemoveAt(vx.Count - 1);
                if (z < n) {
                    A.Add(z);
                    continue;
                }

                var w = vx.Last();
                var i = (A.Count % 2 == 0 ? b[z].IndexOf(g[z][w]) : 0);
                var j = (A.Count % 2 == 1 ? b[z].IndexOf(g[z][A.Last()]) : 0);
                var k = b[z].Count;
                var dif = (A.Count % 2 == 0 ? i % 2 == 1 : j % 2 == 0)
                                            ? 1 : k - 1;
                while (i != j) {
                    vx.Add(b[z][i]);
                    i = (i + dif) % k;
                }
                vx.Add(b[z][i]);
            }
            return A;
        }

        public int Solve() {
            for (int ans = 0; true; ans++) {
                for (int i = 0; i < this.d.Count; i++) 
                    d[i] = 0;
                var Q = new Queue<int>();
                for (int i = 0; i < m; i++) bl[i] = i;
                for (int i = 0; i < n; i++) {
                    if (mate[i] != -1) continue;
                    Q.Enqueue(i);
                    p[i] = i;
                    d[i] = 1;
                }
				int c = n;
				bool aug = false;
				while (Q.Count != 0 && !aug) {
                    int x = Q.Dequeue();
                    if (bl[x] != x) continue;
                    for (int y = 0; y < c; y++) {
                        if (!(bl[y] == y &&  g[x][y] != -1)) continue;
                        if (d[y] == 0) {
                            p[y] = x;
                            d[y] = 2;
                            p[mate[y]] = y;
                            d[mate[y]] = 1;
                            Q.Enqueue(mate[y]);
                        }
                        else if (d[y] == 1) {
                            var vx = Trace(x);
                            var vy = Trace(y);
                            if (vx.Last() == vy.Last()) {
                                this.Contract(c, x, y, vx, vy);
                                Q.Enqueue(c);
                                p[c] = p[b[c][0]];
                                d[c] = 1;
                                c++;
                            } else {
                                aug = true;
                                vx.Insert(0, y);
                                vy.Insert(0, x);
                                var A = Lift(vx);
                                var B = Lift(vy);
                                A.AddRange(B.AsEnumerable().Reverse());
                                for (int i = 0; i < A.Count; i += 2) {
                                    Match(A[i], A[i + 1]);
                                    if (i + 2 < A.Count)
                                        AddEdge(A[i + 1], A[i + 2]);
                                }
                            }
                            break;
                        }
                    }
                }
                if (!aug) return ans;
            }
        }

    }
}

#region Scanner
namespace CompLib.Util
{
    using System;
    using System.Linq;

    class Scanner
    {
        #region input file
        public static string input = @"D:\CompetitiveProgramming\Csharp\input.txt";
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

    public static string input = @"D:\CompetitiveProgramming\Csharp\input.txt";
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
        var sc = new Scanner();
        int n = sc.NextInt();
        int m = sc.NextInt();
        var B = new Blossom(n);
        for (int i = 0; i < m; i++) {
            int u = sc.NextInt();
            int v = sc.NextInt();
            B.AddEdge(u, v);
        }
        System.Console.WriteLine(B.Solve());

        var listMate = B.GetMate();
        for (int i = 0; i < n; i++) {
            if (i < listMate[i]) {
                System.Console.WriteLine(i + " " + listMate[i]);
            }
        }
    }

}