package package02;

public class DemoC3{    
    private static viod ShowObjRef(){
        int [] iArr = new int[10];
        System.out.println(iArr);
        iArr = null;//垃圾回收
    }
    public static void main(String[] args){
        ShowObjRef();
    }
}