(ns addressbook.database)

;
; The database as list of maps.
;

(def db [
        {:salutation "Herr" :first_name "Max" :last_name "Mustermann" :male true :marital_status "ledig"}
        {:salutation "Herr" :first_name "Wilhelm" :last_name "Wunderlich" :male true :marital_status "verheiratet"}
        {:salutation "Frau" :first_name "Liselotte" :last_name "Lustig" :male false :marital_status "verheiratet"}
        {:salutation "Herr" :first_name "Friedrich" :last_name "Freude" :male true :marital_status "verwitwet"}
        {:salutation "Frau" :first_name "Henriette" :last_name "Herrlich" :male false :marital_status "geschieden"}])

;; db

;
; Example 1: Get all women.
;

(defn get_all_women
  [db]
  (filter #(not (:male %)) db))

;; (get_all_women db)

;
; Example 2: Get all women who are married.
;

(defn get_married_women
  [db]
  (filter #(and (= (:marital_status %) "verheiratet") (not (:male %))) db))

;; (get_married_women db)

;
; Example 3: Add a new person to the addressbook.
;

(defn add_person
  [db s f l s ms]
  (conj db {:salutation s :first_name f :last_name l :male s :marital_status ms}))

;; (add_person db "Herr" "Heinrich" "Holunder" true "verheiratet")

;
; Example 4: Change a person's marital status.
;

(defn set_marital_status
  [db n1 n2]
  (let [

    ;
    ; Variante 1: Langdeklaration anonyme Funktion
    ;

    f (fn [quelle] (if (or (= (:last_name quelle) n1) (= (:last_name quelle) n2))
                      (assoc quelle :marital_status "verheiratet")
                      ; Else return unchanged collection.
                      quelle))

    ;
    ; Variante 2: Kurzdeklaration anonyme Funktion
    ;

    ;; f #(if (or (= (:last_name %) n1) (= (:last_name %) n2))
    ;;       (assoc % :marital_status "verheiratet")
    ;;       ; The % returns the unchanged collection.
    ;;       %)

    ; Anwenden Funktion
    result (map f db)

    ;
    ; Variante 3: Ausführlich: eine Collection MIT und eine OHNE
    ; die beiden Personen, am Ende mit "concat" verschmolzen
    ;

    ;; ; Choose person "Mustermann" and "Holunder"
    ;; choice (filter #(or (= (:last_name %) n1) (= (:last_name %) n2)) db)
    ;; ; Change attribute ":marital_status" to "verheiratet"
    ;; verheiratet (map #(assoc % :marital_status "verheiratet") choice)
    ;; ; Choose other people besides "Mustermann" and "Holunder"
    ;; other (filter #(and (not= (:last_name %) "Mustermann") (not= (:last_name %) "Holunder")) db)
    ;; result (concat verheiratet other)
    ]
  result))

;; (set_marital_status db "Mustermann" "Holunder")

;
; Example 5: Change database structure.
;
; Use combined :first_name and :last_name as new key attribute.
; Remove old attributes :first_name und :last_name.
;

(defn change_structure
  [db]
  (let [
    ; Variante 1: Langdeklaration anonyme Funktion
    f (fn [quelle] (assoc quelle :name (str (get quelle :first_name) " " (get quelle :last_name))))
    ; Variante 2: Kurzdeklaration anonyme Funktion
    ;; f #(assoc % :name (str (get % :first_name) " " (get % :last_name)))
    with_key (map f db)
    cleaned (map #(dissoc % :first_name :last_name) with_key)]
  cleaned))

;; (change_structure db)

;
; Example 6: Remove a person from the database.
;

(defn remove_person
  [db m]
  (remove #(= (:last_name %) m) db))

;; (remove_person db "Mustermann")
