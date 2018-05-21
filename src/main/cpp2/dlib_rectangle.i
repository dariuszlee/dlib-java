%typemap(jni) dlib::rectangle "jobject"
%typemap(jtype) dlib::rectangle "java.awt.Rectangle"
%typemap(jstype) dlib::rectangle "java.awt.Rectangle"

%typemap(javadirectorin) dlib::rectangle "$jniinput"
%typemap(directorin) dlib::rectangle
%{
    // typemap(directorin) dlib::rectangle
%}
%typemap(javain) dlib::rectangle "$javainput"
%typemap(in) dlib::rectangle {
    // $1 = TYPEMAP IN
}

%typemap(javadirectorout) dlib::rectangle "$javacall"
%typemap(directorout) dlib::rectangle
%{
    // typemap(directorout) dlib::rectangle
%}
%typemap(javaout) dlib::rectangle {
    return $jnicall;
}
%typemap(out) dlib::rectangle {
    jclass rectangle_class = jenv->FindClass("java/awt/Rectangle");
    jmethodID rectangle_constructor = jenv->GetMethodID(rectangle_class, "<init>", "(IIII)V");

    // TYPEMAP OUT dlib::rectangle -> jobject
    $result = jenv->NewObject(rectangle_class, rectangle_constructor, $1.left(), $1.top(), $1.right() - $1.left() , $1.bottom() - $1.top());
}
