struct linked_list
{
	int value;
	struct linked_list * next_q;
};

struct linked_list next_1(struct linked_list q1) {
	return *(q1.next_q);
}
	

int main() {
	struct linked_list q1;
	struct linked_list q2;
	struct linked_list q3;
	q1.value = 1;
	q2.value = 2;
	q3.value = 3;
	q1.next_q = &q2;
	q2.next_q = &q3;
	printf("%d\n",q1.next_q->next_q->value);
	printf("%d\n", next_1(q1).value);
}

