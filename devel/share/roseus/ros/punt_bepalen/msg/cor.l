;; Auto-generated. Do not edit!


(when (boundp 'punt_bepalen::cor)
  (if (not (find-package "PUNT_BEPALEN"))
    (make-package "PUNT_BEPALEN"))
  (shadow 'cor (find-package "PUNT_BEPALEN")))
(unless (find-package "PUNT_BEPALEN::COR")
  (make-package "PUNT_BEPALEN::COR"))

(in-package "ROS")
;;//! \htmlinclude cor.msg.html


(defclass punt_bepalen::cor
  :super ros::object
  :slots (_x _y ))

(defmethod punt_bepalen::cor
  (:init
   (&key
    ((:x __x) 0)
    ((:y __y) 0)
    )
   (send-super :init)
   (setq _x (round __x))
   (setq _y (round __y))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:serialization-length
   ()
   (+
    ;; int32 _x
    4
    ;; int32 _y
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _x
       (write-long _x s)
     ;; int32 _y
       (write-long _y s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _x
     (setq _x (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _y
     (setq _y (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get punt_bepalen::cor :md5sum-) "bd7b43fd41d4c47bf5c703cc7d016709")
(setf (get punt_bepalen::cor :datatype-) "punt_bepalen/cor")
(setf (get punt_bepalen::cor :definition-)
      "int32 x
int32 y

")



(provide :punt_bepalen/cor "bd7b43fd41d4c47bf5c703cc7d016709")


