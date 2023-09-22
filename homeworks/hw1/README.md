# Homework Assignment 1

This folder contains the materials for Homework Assignment X for the course AMS562_F2023.

## Steps to Complete the Assignment

This folder contains the materials for Homewo
**Step 1: Setup SSH Authentication with GitHub**

- I used ssh-keygen -t ed25519 -C [vinithkumar.pasula@stonybrook.edu ](mailto:vinithkumar.pasula@stonybrook.edu%20)�on terminal for sso authentication.

- To use the newly generated SSH key with GitHub, I added public key to your GitHub account.

- Ran this command to copy your public key to the clipboard: pbcopy < ~/.ssh/id_ed25519.pub

- Then, in the GitHub account settings, navigate to "SSH and GPG keys," and click "New SSH key." Paste the copied key into the key field.

**Step 2: Create a Private Repository on GitHub**

- Logged in to GitHub and created a New Repository using below steps

- Click the "+" icon in the top-right corner of the GitHub homepage and select "New repository."

- Enter "AMS562_F2023" as the repository name.

- Chosen "Private" for visibility (if it's not already selected).

- Added a README file, .gitignore, and license.

x

**Step 3: Organize Repository Structure and commiting and pushing changes in main branch**

- To work with your GitHub repository locally, we have to clone it to your computer using the following command :

- git clone git@github.com:Vinithkumar1397/AMS562_F2023.git

- Used the following commands to create the required directory structure and empty README files:

- cd AMS562_F2023

- mkdir homeworks���

- mkdir midterm_project

cd midterm_project and touch README.MD

���� git add .

���� git commit -m " added readme in midterm project"

���� git push

- mkdir final_project

cd midterm_project and touch README.MD

����� git add .

����� git commit -m " added readme in final project"

����� git push

- touch README.md

**Created Top-Level README**:

- Created a README.md file in the top-level directory

# AMS562_F2023 Repository

This repository contains course materials for AMS562_F2023, including homework assignments, the midterm project, and the final project.

## Directory Structure

- **homeworks**: Contains subfolders for individual homework assignments.

- **midterm_project**: Placeholder for the midterm project.

- **final_project**: Placeholder for the final project.

- cd ../..

- git add.

- git commit -m " modified readme with the directory structure"

- git push

**Step 4: Create a Branch for Homework 1**

- Created a New Branch for Homework 1 with git checkout -b homeworks/hw1

- Added README.md for Homework 1

-   Inside the newly created branch, created a folder for homework 1 and add a README.md file inside it with following commands:
-   mkdir homeworks/hw1

- touch homeworks/hw1/README.md

- Edited the homeworks/hw1/README.md file using vi editor to describe the homework assignment which is also sent to the professor.

**Step 5: Commit and Push Changes in homeworks/hw1 branch**

�Commit Your Changes:

-   git add.

- git commit -m "Add README for homework 1"

- git push origin homeworks/hw1

**Step 6:� Added Collaborator to GitHub Repository**

-   On the GitHub website, navigated to my repository.
-   "Settings" -> Collaborators" -> Enter "Ams562" -> Clicked "Add collaborator."

**Step 7: Creating a pull request (PR) to wait for a merge from the homeworks/hw1 branch to the main branch**

-   git checkout homeworks/hw1�
-   Ran this command to pull the latest changes from the remote repository to your local branch
-   git pull origin homeworks/hw1�
-   pushed changes to the**homeworks/hw1**branch on GitHub:
-   git push origin homeworks/hw1�

**Created a Pull Request (PR) on GitHub**:

-   On the Github Repository I saw message indicating that I recently pushed to the�**homeworks/hw1**�branch and "Compare & pull request" button next to it.
-   I added �title and description to explain the changes you made in the README file.
-   I specified �the base branch as�**main**� and Created the pull request.
