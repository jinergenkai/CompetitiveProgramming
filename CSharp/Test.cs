using NUnit.Framework;


[TestFixture]
public class MyTests
{
    [Test]
    public void TestAddition()
    {
        int result = Calculator.Add(2, 2);
        Assert.AreEqual(4, result);
    }

    [Test]
    public void TestSubtraction()
    {
        int result = Calculator.Subtract(5, 2);
        Assert.AreEqual(3, result);
    }
}

public class Calculator
{
    public static int Add(int a, int b)
    {
        return a + b;
    }

    public static int Subtract(int a, int b)
    {
        return a - b;
    }
}