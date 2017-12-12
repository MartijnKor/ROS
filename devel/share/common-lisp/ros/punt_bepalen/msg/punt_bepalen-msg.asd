
(cl:in-package :asdf)

(defsystem "punt_bepalen-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "cor" :depends-on ("_package_cor"))
    (:file "_package_cor" :depends-on ("_package"))
  ))