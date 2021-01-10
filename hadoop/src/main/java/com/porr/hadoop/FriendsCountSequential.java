package com.porr.hadoop;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class FriendsCountSequential {

    public static void main(String[] args) throws FileNotFoundException, InterruptedException {

        final long start = System.currentTimeMillis();

        final File file = new File("../openmp/input/list128k.txt");
        final Scanner scanner = new Scanner(file);

        final Map<Integer, Integer> friends = new HashMap<>();
        while (scanner.hasNext()) {
            final int vertexA = scanner.nextInt();
            final int vertexB = scanner.nextInt();
            final Integer friendsOfA = friends.getOrDefault(vertexA, 0);
            final Integer friendsOfB = friends.getOrDefault(vertexB, 0);
            friends.put(vertexA, friendsOfA + 1);
            friends.put(vertexB, friendsOfB + 1);
        }
        final long end = System.currentTimeMillis();
        System.out.println(end - start);
    }
}
