; Auto-generated. Do not edit!


(cl:in-package punt_bepalen-msg)


;//! \htmlinclude cor.msg.html

(cl:defclass <cor> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:integer
    :initform 0)
   (y
    :reader y
    :initarg :y
    :type cl:integer
    :initform 0))
)

(cl:defclass cor (<cor>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <cor>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'cor)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name punt_bepalen-msg:<cor> is deprecated: use punt_bepalen-msg:cor instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <cor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader punt_bepalen-msg:x-val is deprecated.  Use punt_bepalen-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <cor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader punt_bepalen-msg:y-val is deprecated.  Use punt_bepalen-msg:y instead.")
  (y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <cor>) ostream)
  "Serializes a message object of type '<cor>"
  (cl:let* ((signed (cl:slot-value msg 'x)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <cor>) istream)
  "Deserializes a message object of type '<cor>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'x) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'y) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<cor>)))
  "Returns string type for a message object of type '<cor>"
  "punt_bepalen/cor")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'cor)))
  "Returns string type for a message object of type 'cor"
  "punt_bepalen/cor")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<cor>)))
  "Returns md5sum for a message object of type '<cor>"
  "bd7b43fd41d4c47bf5c703cc7d016709")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'cor)))
  "Returns md5sum for a message object of type 'cor"
  "bd7b43fd41d4c47bf5c703cc7d016709")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<cor>)))
  "Returns full string definition for message of type '<cor>"
  (cl:format cl:nil "int32 x~%int32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'cor)))
  "Returns full string definition for message of type 'cor"
  (cl:format cl:nil "int32 x~%int32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <cor>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <cor>))
  "Converts a ROS message object to a list"
  (cl:list 'cor
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
))
