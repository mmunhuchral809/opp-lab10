#pragma once

// Холбоот жагсаалтын нэг элемент (зангилаа)
// T - дурын төрлийн өгөгдөл хадгална
template <typename T>
class Node {
public:
    T data;       // Хадгалах өгөгдөл
    Node* next;   // Дараагийн зангилаа руу заах pointer

    Node(T d) : data(d), next(nullptr) {}
};