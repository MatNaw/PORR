package com.porr.hadoop;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class FriendsCountSequential {

    public static void main(String[] args) throws FileNotFoundException, InterruptedException {

        final long start = System.currentTimeMillis();

        final File file = new File("../openmp/input/list512k.txt");
        final Scanner scanner = new Scanner(file);

        final Map<Integer, Integer> friends = new HashMap<>();
        while (scanner.hasNext()) {
            final String a = scanner.next();
            if(a.startsWith("%")){
                continue;
            }
            final String b = scanner.next();
            final int vertexA = Integer.valueOf(a);
            final int vertexB = Integer.valueOf(b);
            final Integer friendsOfA = friends.getOrDefault(vertexA, 0);
            final Integer friendsOfB = friends.getOrDefault(vertexB, 0);
            friends.put(vertexA, friendsOfA + 1);
            friends.put(vertexB, friendsOfB + 1);
            System.out.println(vertexA + " " + vertexB);
    }
        final long end = System.currentTimeMillis();
        System.out.println(end - start);
    }
}
