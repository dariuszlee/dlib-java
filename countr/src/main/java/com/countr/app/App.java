package com.countr.app;

/** Hello world! */
public class App {
  public static void main(String[] args) {
    FaceDetectionApiDlib api = new FaceDetectionApiDlib();
    try {
      api.setUp();
      api.testComputeFaceDescriptor();
    } catch (Exception e) {
      System.exit(1);
    }
  }
}
