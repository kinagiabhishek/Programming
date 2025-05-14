package java.algos;

import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

public class StreamsAPI {
    public static void main(String args[]) {
        int[] arr = {10,15,8,49,25,98,98,32,15};
        String input = "Java Articles are Awesome";
        List<Integer> list = Arrays.asList(10, 15, 8, 49, 25, 98, 32);
        list.stream()
                .map(n -> n % 2 == 0)
                .forEach(System.out::println);

        list.stream()
                .filter(n -> n % 2 == 1)
                .forEach(System.out::println);
        HashSet<Character> visitedChars = new HashSet<>();
        Character ans = input.chars()
                .mapToObj(c -> (char)c)
                .filter(c ->!visitedChars.add(c))
                .findFirst()
                .orElse(null);
        System.out.println(ans);
    }
}
