# CS-300-DSA-Analysis-and-Design
# Reflection on Data Structure Implementation and Analysis

In CS-300 DSA: Analysis and Design, a significant amount of work was dedicated to analyzing and implementing various data structures to efficiently manage and manipulate a set of course data. Each project focused on different data structures, including vectors, hash tables, binary search trees (BST), and their respective advantages and disadvantages in the context of course management systems. These projects were not just exercises in implementation but also involved in-depth runtime analysis, which guided the choice of the most suitable data structure for a given scenario.

The first project analyzed the use of **vectors**, a simple yet powerful structure that allows sequential access to elements. The implementation included loading course data from a file, sorting the courses alphanumerically, and searching for specific course information. While vectors are easy to implement and perform well with smaller datasets, their performance can degrade with larger datasets, especially when frequent insertions, deletions, or searches are required. This project highlighted the balance between simplicity and efficiency and underscored the importance of considering dataset size when choosing a data structure.

The second project focused on **hash tables**, known for their fast access times. The hash table implementation allowed for rapid insertion and retrieval of course data using hash keys derived from course IDs. Despite their efficiency, hash tables come with the risk of collisions, which can degrade performance. The project also involved a runtime analysis that compared the average-case and worst-case scenarios, illustrating how collisions and the need for proper hash function design can impact overall performance. This analysis helped in understanding the trade-offs between speed and complexity.

The **binary search tree** was the focus of the third project. BSTs offer an efficient means of organizing data for quick search, insertion, and in-order traversal operations. The implementation involved building a tree from course data and validating prerequisites within the tree. The reflection on this project emphasized the importance of maintaining a balanced tree to prevent performance degradation, as unbalanced trees can result in inefficient operations comparable to those of a linked list. The project showcased how BSTs can be a versatile choice, especially when the data requires frequent sorting or when the dataset is dynamic.

Through these projects, I gained a deeper appreciation for the subtleties of data structure selection based on specific use cases. The analyses not only reinforced theoretical knowledge but also provided practical insights into how different data structures behave under various conditions. These projects underscored the critical role that runtime analysis plays in making informed decisions about which data structure to use, depending on the specific requirements of the application, such as speed, memory efficiency, and ease of implementation. Overall, this experience has sharpened my ability to critically evaluate and implement data structures in a way that aligns with the goals of a given project.
